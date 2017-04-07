#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n, k, tmp1, tmp2;
    map<int, int> occ;
    cin >> t;
    while(t--) {
        occ.clear();
        cin >> n >> k;
        vector<vector<int> > e(n);
        for (int i = 0; i < n; i++) {
            cin >> tmp1;
            while(tmp1--) {
                cin >> tmp2;
                e[i].push_back(tmp2);
                occ[tmp2] = (occ.count(tmp2)) ? occ[tmp2] + 1 : 1;
            }
        }
        if (occ.size() < k) cout << "sad\n";
        else {
            bool skipped = false;
            for (int i = 0; i < e.size() && !skipped; i++) {
                skipped = true;
                for (int j = 0; j < e[i].size(); j++) {
                    if (occ[e[i][j]] == 1) skipped = false;
                }
            }
            cout << ((skipped) ? "some\n" : "all\n");
        }
    }

    return 0;
}
