/*
ID: rathore1
PROG: milk
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    ofstream cout ("milk.out");
    ifstream cin ("milk.in");

    int n, m, cost = 0;
    cin >> n >> m;
    vector<pair<int, int> > milks(m);
    for (int i = 0; i < m; i++) cin >> milks[i].first >> milks[i].second;
    sort(milks.begin(), milks.end());
    for (int i = 0; i < m, n > 0; i++) {
        int b = min(n, milks[i].second);
        cost += milks[i].first * b;
        n -= b;
    }
    cout << cost << endl;
    return 0;
}
