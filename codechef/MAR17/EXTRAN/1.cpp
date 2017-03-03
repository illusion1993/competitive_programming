#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, in, dupe;
    map<int, bool> is_nice;
    map<int, bool> occ;
    typedef map<int, bool>::iterator map_iterator;

    cin >> t;
    while(t--) {
        is_nice.clear();
        occ.clear();
        dupe = 0;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> in;

            if (occ.count(in)) {
                dupe = in;
            }

            is_nice[in] = false;
            occ[in] = true;
            if (is_nice.count(in - 1)) {
                is_nice[in - 1] = true;
                is_nice[in] = true;
            }
            if (is_nice.count(in + 1)) {
                is_nice[in + 1] = true;
                is_nice[in] = true;
            }
        }
        if (dupe) cout << dupe << "\n";
        else {
            for (map_iterator i = is_nice.begin(); i != is_nice.end(); i++) {
                if (!i -> second) {
                    cout << i -> first << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}
