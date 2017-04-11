#include<bits/stdc++.h>
using namespace std;

int n;
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



int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int t, m;
    cin >> t;
    while(t--) {
        cin >> m >> n;
        cin >> path;
        char ch;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> ch;
                is_hole[i][j] = (ch == '#');
            }
        }
        Brute b;
        cout << b.computeAns() << "\n";
    }

    return 0;
}
