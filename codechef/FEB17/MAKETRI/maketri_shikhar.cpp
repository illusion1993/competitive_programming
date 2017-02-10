#include <bits/stdc++.h>
using namespace std;

int n;
long long l, r, marker, a[1000000], ans;

vector<pair<long long, long long> > intervals;

int main() {
    int n;
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    for (int i = 1; i < n; i++) {
        intervals.push_back(make_pair(abs(a[i] - a[i - 1]) + 1, a[i] + a[i - 1] - 1));
    }
    sort(intervals.begin(), intervals.end());

    marker = l - 1;
    ans = r - l + 1;

    for (int i = 0; i < n - 1; i++) {
        if (intervals[i].first <= intervals[i].second) {
            if (marker < intervals[i].first) {
                ans -= (min(r + 1, intervals[i].first) - marker - 1);
            }
            marker = max(marker, intervals[i].second);
        }
        if (marker >= r) break;
    }
    ans -= (r - min(r, marker));
    cout << ans << endl;
    return 0;
}

/*
Let's choose three continuous values a, b, c

Valid sides lie in:

(b - a + 1, a + b - 1)
(c - a + 1, a + c - 1)
(c - b + 1, b + c - 1)

Now since a < b => (c - a + 1) > (c - b + 1)
Also, since a < b => (c + b + 1) > (c + a + 1)

=> (c - a + 1, a + c + 1) is covered by (c - b + 1, b + c + 1). Same goes for all values with one fixed side c and other side chosen from array with len less than c.Therefore, using the continous pairs approach all possible third sides "for side c" can be calculated.
*/
