#include<bits/stdc++.h>
using namespace std;

bool sortInterval(const pair<long long, long long> &a, const pair<long long, long long> &b) {
    return a.first < b.first;
}

bool isOverlap(pair<long long, long long> a, pair<long long, long long> b) {
    return (max(a.first, b.first) <= min(a.second, b.second) + 1);
}

int main() {
    int n;
    long long l, r, a[1000000], count = 0, least, most;

    vector<pair<long long, long long> > intervals;

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n - 1; j++) {
            least = a[j] - a[i] + 1;
            most = a[j] + a[i] - 1;
            if (max(l, least) <= min(r, most)) {
                intervals.push_back(make_pair(max(l, least), min(r, most)));
            }
        }
    }

    sort(intervals.begin(), intervals.end(), sortInterval);
    stack<pair<long long, long long> > final_intervals;
    if (intervals.size()) final_intervals.push(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        if (isOverlap(final_intervals.top(), intervals[i])) {
            final_intervals.top().first = min(final_intervals.top().first, intervals[i].first);
            final_intervals.top().second = max(final_intervals.top().second, intervals[i].second);
        }
    }

    //cout << endl << endl << "Intervals are: " << endl;
    while(!final_intervals.empty()) {
        //cout << final_intervals.top().first << " - " << final_intervals.top().second << endl;
        count += final_intervals.top().second - final_intervals.top().first + 1;
        final_intervals.pop();
    }
    cout << count;

    return 0;
}
