#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    long long a[100000];
    bool accept = false;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {

                if (a[i] + a[j] > a[k] && a[i] + a[k] > a[j] && a[k] + a[j] > a[i]) {
                    accept = true;
                    break;
                }

            }
            if (accept) break;
        }
        if (accept) break;
    }

    if (accept) cout << "YES";
    else cout << "NO";

    return 0;
}
