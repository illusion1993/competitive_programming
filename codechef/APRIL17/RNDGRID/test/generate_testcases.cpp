#include<bits/stdc++.h>
using namespace std;

int t, m, n, prob;
string path;
bool is_hole[1000][1000];

class Brute {
public:
    int computeAns() {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!is_hole[i][j]) ans = ans ^ countMovesFrom(i, j);
            }
        }
        return ans;
    }
private:
    bool isValidPos(int r, int c) {
        return (r >= 0 && c >= 0 && r < n && c < n && !is_hole[r][c]);
    }

    int countMovesFrom(int r, int c) {
        int m = -1, a = r, b = c;
        for (int i = 0; i < path.length() && isValidPos(a, b); i++) {
            m++;
            if (path[i] == 'R') b++;
            else if (path[i] == 'L') b--;
            else if (path[i] == 'U') a--;
            else a++;
        }
        if (isValidPos(a, b)) m++;
        return m;
    }
};

class Opt{
public:
    int computeAns() {
        decomposePath();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!is_hole[i][j]) ans = ans ^ countMovesFrom(i, j);
            }
        }
        return ans;
    }
private:
    vector<pair<pair<int, int>, int> > checks;
    bool isValidPos(int r, int c) {
        return (r >= 0 && c >= 0 && r < n && c < n && !is_hole[r][c]);
    }

    void decomposePath() {
        checks.clear();
        map<pair<int, int>, bool> checked;
        checked[{0, 0}] = 1;
        int r = 0, c = 0, scr = -1;
        for (int i = 0; i < path.length(); i++) {
            scr++;
            if (path[i] == 'R') c++;
            else if (path[i] == 'L') c--;
            else if (path[i] == 'U') r--;
            else r++;

            if (!checked.count({r, c})) {
                checked[{r, c}] = 1;
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
};

void gen() {
    char moves[4], pieces[2];
    moves[0] = 'L';
    moves[1] = 'R';
    moves[2] = 'U';
    moves[3] = 'D';
    path = "";
    memset(is_hole, 0, sizeof(is_hole));

    for (int i = 0; i < m; i++) path += moves[rand() % 4];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) is_hole[i][j] = ((rand() % 100) + 1 <= prob);
}

int main(int argc, char const *argv[])
{
    srand(time(0));

    t = 100;
    m = 6;
    n = 10;
    prob = 20;

    int a1, a2;
    Brute b;
    Opt o;

    // cout << t << endl;
    for (int tc = 1; tc <= t; tc++) {
        gen();
        a1 = b.computeAns();
        a2 = o.computeAns();

        cout << a1 << " " << a2 << " ";
        if (a1 == a2) cout << " <- OK\n";
        if (a1 != a2){
            cout << m << " " << n << endl;
            cout << path << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) cout << ((is_hole[i][j]) ? '#' : '.');
                cout << endl;
            }
        }
    }

    return 0;
}
