#include<bits/stdc++.h>
using namespace std;

vector<int> a;

int main(void) {
    srand(time(0));
    int t, n, m, l1, r1, l2, r2;
    cin >> t;
    n = 50;
    m = 1;

    cout << t << endl;
    while(t--) {
        vector<pair<int, int> > arr;
        vector<int> x;
        vector<int> y;
        int separated = 0;

        for (int i = 0; i < n; i++) {
            arr.push_back({(rand() % 100) + 1, 0});
        }

        sort(arr.begin(), arr.end());
        for (int i = 0; i < (n/2) - 1; i++) {
            arr[(i * 2) + 1 + (rand() % 2)].second = 1;
        }
        arr[arr.size() - 1].second = 1;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i].second) y.push_back(arr[i].first);
            else x.push_back(arr[i].first);
        }
        a.insert(a.end(), x.begin(), x.end());
        a.insert(a.end(), y.begin(), y.end());

        cout << n << " " << m << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < m; i++) {
            l1 = 1;
            r1 = n / 2;
            l2 = r1 + 1;
            r2 = n;
            cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
        }
    }
    return 0;
}
