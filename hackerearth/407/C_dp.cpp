#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a[100000], m;
	long long dp0, dp1, max_f, ndp0, ndp1;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	dp0 = LLONG_MIN;
	dp1 = abs(a[1] - a[0]);
	max_f = dp1;

	for (int i = 2; i < n; i++) {
		ndp0 = dp1 - abs(a[i] - a[i - 1]);
		ndp1 = max(dp0 + abs(a[i] - a[i - 1]), (long long)abs(a[i] - a[i - 1]));
		dp0 = ndp0;
		dp1 = ndp1;
		max_f = max(max_f, dp0);
		max_f = max(max_f, dp1);
	}

	cout << max_f;

	return 0;
}