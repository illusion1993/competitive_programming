#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[200000], b[200000];

vector<pair<int, pair<int, int> > > costs;
int computeCost() {
    for (int i = 0; i < n; i++) {
        costs.push_back(make_pair(a[i] - b[i], make_pair(a[i], b[i])));
    }

    sort(costs.begin(), costs.end());

    int cost = 0;
    int i;
    for (i = 0; i < k; i++) cost += costs[i].second.first;
    while(i < n) {
        if (costs[i].first < 0) cost += costs[i].second.first;
        else cost += costs[i].second.second;
        i++;
    }
    return cost;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    cout << computeCost();

    return 0;
}
