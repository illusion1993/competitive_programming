#include<bits/stdc++.h>
using namespace std;

int n, a[100000];

vector<pair<int, int> > number_range;
vector<int> options_count;

bool sortNumberRange(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

void buildNumberRange(int l1, int r1, int l2, int r2) {
    number_range.clear();
    for (int i = 0; i < max(r1, r2); i++) {
        if (i >= l1 - 1 && i <= r1 - 1) number_range.push_back({a[i], 0});
        else if (i >= l2 - 1 && i <= r2 - 1) number_range.push_back({a[i], 1});
    }
    sort(number_range.begin(), number_range.end(), sortNumberRange);
}

void findOptionsCount() {
    options_count.clear();
    for (int i = 0; i < number_range.size(); i++) {
        if (number_range[i].second) options_count.push_back(i - options_count.size());
    }
}

int countCombs(int l1, int r1, int l2, int r2) {
    int combs;
    buildNumberRange(l1, r1, l2, r2);

    /*
    cout << "Number Range is: ";
    for (int i = 0; i < number_range.size(); i++) {
        cout << number_range[i].first << ":" << number_range[i].second << " ";
    }
    cout << endl;*/

    findOptionsCount();
    combs = options_count[0];
    for (int i = 1; i < options_count.size(); i++) {
        combs = (combs * (options_count[i] - i)) % 1000000007;
    }

    /*cout << "Options counts are: ";
    for (int i = 0; i < options_count.size(); i++) cout << options_count[i] << " ";
    cout << endl;*/

    return combs;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int t, m, l1, r1, l2, r2;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> l1 >> r1 >> l2 >> r2;
            cout << countCombs(l1, r1, l2, r2) << "\n";
        }
    }
    return 0;
}
