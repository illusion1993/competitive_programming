#include <bits/stdc++.h>
using namespace std;


int main() {
    int s, n;
    long long in;
    vector<long long> dp_old, dp_new, coins;
    cin >> s >> n;
    for (int i = 0; i < n; i++) {
        cin >> in;
        coins.push_back((int)in);
    }
    dp_old.push_back(1);
    for (int i = 0; i < s; i++) dp_old.push_back(0);
    for (int i = 0; i < n; i++) {
        dp_new.clear();
        dp_new.push_back(1);
        for (int j = 1; j <= s; j++) {
            in = dp_old[j];
            for (int k = j - coins[i]; k >= 0; k -= coins[i]) {
                in += dp_old[k];
            }
            dp_new.push_back(in);
        }
        dp_old = dp_new;
    }
    cout << dp_new.back();
    return 0;
}
