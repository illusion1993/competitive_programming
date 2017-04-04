/*
ID: rathore1
PROG: barn1
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    ofstream cout ("barn1.out");
    ifstream cin ("barn1.in");

    int n, m, c;
    cin >> n >> m >> c;
    vector<int> a(c), diff;
    for (int i = 0; i < c; i++) cin >> a[i];
    sort(a.begin(), a.end());
    m = a[c - 1] - a[0] + 1;
    for (int i = 1; i < c; i++) if (a[i] > a[i - 1] + 1) diff.push_back(a[i] - a[i - 1] - 1);
    sort(diff.rbegin(), diff.rend());
    for (int i = 0; i < n - 1 && i < diff.size(); i++) m -= diff[i];
    cout << m << endl;
    return 0;
}
