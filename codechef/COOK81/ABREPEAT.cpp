#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    string s;
    ll ans, n, k;
    
    cin >> t;
    while(t--) {
        cin >> n >> k >> s;
        ans = 0;
        ll total_b = 0, total_a = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == 'b') total_b++;
            else if (s[i] == 'a') {
                ans += (total_b * k);
                total_a++;
            }
        }
        ans += (((k - 1) * k * total_a) / 2) * total_b;
        cout << ans << "\n";
    }
    return 0;
}
