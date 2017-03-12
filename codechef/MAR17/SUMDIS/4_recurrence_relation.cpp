#include<bits/stdc++.h>
using namespace std;

int t, n;
long long sumdis, sumsh[300001], sh[300001][3], in;

void make_sumsh() {
    long long local_sumsh;
    for (int i = 2; i < 5; i++) {
        local_sumsh = 0;
        for (int j = 1; j < i; j++) local_sumsh += sh[j][i - j - 1];
        sumsh[i] = local_sumsh;
        sumdis += sumsh[i];
        cout << "sumsh " << i << " is " << sumsh[i] << "\n";
    }
    for (int i = 5; i <= n; i++) {
        sumsh[i] = sumsh[i - 3] + (sh[i - 3][2] * (i - 3)) + sh[i - 2][1] + sh[i - 1][0];
        sumsh[i] = min(sumsh[i], sumsh[i - 2] + (sh[i - 2][1] * (i - 2)) + sh[i - 1][0]);
        sumsh[i] = min(sumsh[i], sumsh[i - 1] + (sh[i - 1][0] * (i - 1)));
        sumdis += sumsh[i];
        cout << "sumsh " << i << " is " << sumsh[i] << "\n";
    }
}

void process_input() {
    sumdis = 0;
    memset(sh, 0, sizeof(sh));
    memset(sumsh, 0, sizeof(sumsh));

    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        cin >> sh[i][0];
    }
    for (int i = 1; i <= n - 2; i++) {
        cin >> in;
        sh[i][1] = min(in, sh[i][0] + sh[i + 1][0]);
    }
    for (int i = 1; i <= n - 3; i++) {
        cin >> in;
        sh[i][2] = min(in, sh[i][0] + sh[i + 1][1]);
        sh[i][2] = min(sh[i][2], sh[i][1] + sh[i + 2][0]);
    }

    cout << "SH info: \n";
    for (int i = 1; i < n; i++) {
        cout << i << " - " << i + 1 << ": " << sh[i][0] << "\n";
        cout << i << " - " << i + 2 << ": " << sh[i][1] << "\n";
        cout << i << " - " << i + 3 << ": " << sh[i][2] << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        process_input();
        make_sumsh();
        cout << sumdis << "\n";
    }

    return 0;
}
