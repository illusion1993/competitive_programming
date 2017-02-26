#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, in;
    int a[200000], b[200000];
    int dp0[200001], dp1[200001];

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    dp0[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp0[i] = dp0[i - 1] + min(a[i - 1], b[i - 1]);
    }

    for (int i = 1 ; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            if (i % 2) {
                if (j == i) dp1[j] = dp0[j - 1] + a[j - 1];
                else if (j > i) dp1[j] = min(dp0[j - 1] + a[j - 1], dp1[j - 1] + b[j - 1]);
                else dp1[j] = 0;
            }
            else {
                if (j == i) dp0[j] = dp1[j - 1] + a[j - 1];
                else if (j > i) dp0[j] = min(dp1[j - 1] + a[j - 1], dp0[j - 1] + b[j - 1]);
                else dp0[j] = 0;
            }
        }
    }

    if (k % 2) cout << dp1[n];
    else cout << dp0[n];

    return 0;
}
