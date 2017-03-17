#include<bits/stdc++.h>
using namespace std;

map<int, bool> once;
map<int, int> more;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, h;
    long long pairs;
    cin >> t;
    while(t--) {
        once.clear();
        more.clear();
        pairs = 0;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> h;
            if (more.count(h)) {
                more[h]++;
            }
            else if (once.count(h)) {
                more[h] = 2;
                once.erase(h);
            }
            else once[h] = true;
        }

        for(map<int,int>::iterator it = more.begin(); it != more.end(); ++it) {
            pairs += it -> second * (it -> second - 1);
        }

        cout << pairs << "\n";

    }
    return 0;
}
