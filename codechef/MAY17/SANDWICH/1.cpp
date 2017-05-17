#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t, m;
ll n, k, l, p;

unordered_map<ll, unordered_map<ll, int> > dp;
int get_dp(ll len, ll parts) {
	// cout << "called for " << len << ", " << parts << "\n";

	if (len <= k) {
		// cout << "1\n";
		return 1;
	}
	if (len > k && parts == 1) {
		// cout << "0\n";
		return 0;
	}
	if (dp.count(len) && dp[len].count(parts)) {
		// cout << "Found: " << dp[len][parts] << "\n";
		return dp[len][parts];
	}
	int dpval = 0;
	for (ll i = len - l; i >= 0 && i >= len - k; i--) {
		dpval = (dpval + get_dp(i, parts - 1)) % m;
		// cout << "dpval became: " << dpval << " for " << len << ", " << parts << "\n";
	}
	if (!dp.count(len)) {
		unordered_map<ll, int> x;
		dp[len] = x;
	}
	dp[len][parts] = dpval;
	return dpval;
}

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
    cin.tie(0);
    
	cin >> t;
	while(t--) {
		dp.clear();
		cin >> n >> k >> m;
		l = n % k;
		p = (n / k) + (n % k != 0);
		cout << p << " " << get_dp(n, p) << "\n";
	}

	return 0;
}