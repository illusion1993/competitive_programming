#include<bits/stdc++.h>
using namespace std;

int n, m, l, r, k;
long long current, prev = -1;

map<int, pair<long long, int> > val;

int main() {
    cin >> n >> m;
    bool on = false;
    int first_seen;

    for (int i = 0; i < n; i++) {
        cin >> current;

        if (current == prev && !on) {
            on = true;
            first_seen = i - 1;
        }
        else if (on && current != prev) {
            on = false;
            pair<long long, int> this_interval(prev, i - first_seen);

            for (int j = first_seen; j <= i - 1; j++) val[j] = this_interval;
        }
        else if (on && i == n - 1) {
            on = false;
            pair<long long, int> this_interval(prev, i + 1 - first_seen);

            for (int j = first_seen; j <= i; j++) val[j] = this_interval;
        }
        prev = current;
    }

    for (int i = 0; i < m; i++) {
        cin >> l >> r >> k;
        l--;
        r--;
        int mid = (l + r) / 2;
        if (val.count(mid) && val[mid].second >= k) cout << val[mid].first << endl;
        else cout << "-1" << endl;
    }

    return 0;
}
