#include<bits/stdc++.h>
using namespace std;

int n;
long long l, r, a[1000000];
vector<pair<long long, long long> > ranges;
long long ans;

bool sortInterval(const pair<long long, long long> &a, const pair<long long, long long> &b) {
    return a.first < b.first;
}

void mergeRanges() {
    ans = 0;
    if (!ranges.size()) return;
    sort(ranges.begin(), ranges.end(), sortInterval);

    pair<long long, long long> current_merged_range;
    current_merged_range = ranges[0];

    for (int i = 1; i < ranges.size(); i++) {
        if (max(current_merged_range.first, ranges[i].first) > min(current_merged_range.second, ranges[i].second)) {
            //cout << current_merged_range.first << " - " << current_merged_range.second << endl;
            ans += current_merged_range.second - current_merged_range.first + 1;
            current_merged_range = ranges[i];
        }
        else {
            current_merged_range.first = min(current_merged_range.first, ranges[i].first);
            current_merged_range.second = max(current_merged_range.second, ranges[i].second);
        }
    }
    //cout << current_merged_range.first << " - " << current_merged_range.second << endl;
    ans += current_merged_range.second - current_merged_range.first + 1;
}

int main() {
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) cin >> a[i];

    pair<long long, long long> this_range;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (max(abs(a[j] - a[i]) + 1, l) <= min(abs(a[j] + a[i]) - 1, r))
                ranges.push_back(make_pair(max(abs(a[j] - a[i]) + 1, l), min(abs(a[j] + a[i]) - 1, r)));
        }
    }

    //cout << "Ranges are found to be: " << endl;
    //for (int i = 0; i < ranges.size(); i++) cout << ranges[i].first << " - " << ranges[i].second << endl;

    //cout << "Merging ranges now. ranges are: " << endl;
    mergeRanges();

    cout << ans;

    return 0;
}
