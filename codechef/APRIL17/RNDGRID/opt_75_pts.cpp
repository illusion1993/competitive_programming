#include<bits/stdc++.h>
#include <boost/functional/hash.hpp>
using namespace std;
 
int n;
string path;
bool is_hole[1000][1000];
vector<pair<int, int> > cells;
vector<pair<pair<int, int>, int> > checks;
 
bool isValidPos(int r, int c) {
    return (r >= 0 && c >= 0 && r < n && c < n && !is_hole[r][c]);
}
 
void decomposePath() {
    checks.clear();
    unordered_set<pair<int, int>, boost::hash< std::pair<int, int> > > checked;
    checked.insert({0, 0});
 
    int r = 0, c = 0, scr = -1;
    for (int i = 0; i < path.length(); i++) {
        scr++;
        if (path[i] == 'R') c++;
        else if (path[i] == 'L') c--;
        else if (path[i] == 'U') r--;
        else r++;
 
        if (!checked.count({r, c})) {
            checked.insert({r, c});
            checks.push_back({{r, c}, scr});
        }
    }
}
 
int countMovesFrom(int r, int c) {
    for (int i = 0; i < checks.size(); i++) {
        if (!isValidPos(r + checks[i].first.first, c + checks[i].first.second)) return checks[i].second;
    }
    return path.length();
}
 
void inputArray() {
    memset(is_hole, 0, sizeof(is_hole));
    cells.clear();
    char ch;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ch;
            if (ch == '.') cells.push_back({i, j});
            else is_hole[i][j] = 1;
        }
    }
}
 
int computeAns() {
    int ans = 0;
    for (int i = 0; i < cells.size(); i++) ans = ans ^ countMovesFrom(cells[i].first, cells[i].second);
    return ans;
}
 
int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t, m;
 
    cin >> t;
    while(t--) {
        cin >> m >> n;
        cin >> path;
        decomposePath();
        inputArray();
        cout << computeAns() << "\n";
    }
 
    return 0;
}