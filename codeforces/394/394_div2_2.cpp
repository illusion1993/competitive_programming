#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, l;
    int a[50], b[50], da[50], db[50];
    bool flag = false;

    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) da[i - 1] = a[i] - a[i - 1];
    }

    da[n - 1] = a[0] + (l - a[n-1]);

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (i > 0) db[i - 1] = b[i] - b[i - 1];
    }
    db[n - 1] = b[0] + (l - b[n-1]);

    for (int i = 0; i < n; i++) {
        if (db[i] == da[0]) {
            flag = true;
            for (int j = 1; j < n; j++) {
                if (da[j] != db[(i + j) % n]) {
                    flag = false;
                }
            }
        }
        if (flag) break;
    }

    if (flag) cout << "YES";
    else cout << "NO";

}
