#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

#define s_lim 1000
#define n_lim 100

int dp[s_lim + 1][n_lim + 1];

int f(int s, int n) {
    if (s < 0 || n < 0) return 0;
    return dp[s][n];
}

void make_dp() {
	memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 52; i++) dp[i][1] = 1;
	for (int i = 1; i <= n_lim; i++) dp[i][i] = 1;

	for (int j = 2; j <= n_lim; j++) {
		for (int i = j + 1; i < s_lim; i++) {
			dp[i][j] = (f(i - 1, j) + f(i - 1, j - 1)) % mod;
			if (dp[i][j] < f(i - 53, j - 1)) {
				dp[i][j] = mod - (f(i - 53, j - 1) - dp[i][j]);
			}
			else dp[i][j] -= f(i - 53, j - 1);
		}
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    
    make_dp();
    
    int n, m, k, w = 0, max_w;
    string s;
    
    cin >> n >> m >> k >> s;
    max_w = n * 52;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] <= 'z' && s[i] >= 'a') w += ((int)s[i] - 96);
        if (s[i] <= 'Z' && s[i] >= 'A') w += ((int)s[i] - 64);
    }
    
    int poss_w = k;
    
    while (poss_w - w < n) poss_w += m;
    poss_w -= w;
    
    int ans = 0;
    do {
        // cout << "poss_w is " << poss_w << endl;
        ans = (ans + f(poss_w, n)) % mod;
        cout << f(poss_w, n) << "\n";
        cout << "After f(" << poss_w << ", " << n << "), ans is " << ans << endl;
        poss_w += m;
    }
    while (poss_w <= max_w);
    
    cout << ans;
    
    return 0;
}