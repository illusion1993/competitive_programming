#include <bits/stdc++.h>
using namespace std;
#define lim 2000000

vector<int> even_sum;
vector<int> odd_sum;
vector<int> diff;

long long extra;
vector<long long> dp;

void precompute() {
	for (int i = 0; i < 10; i++) {
		if (i % 2) {
			odd_sum.push_back(i);
			even_sum.push_back(0);
		}
		else {
			odd_sum.push_back(0);
			even_sum.push_back(i);
		}
		diff.push_back(abs(even_sum[i] - odd_sum[i]));
	}
	for (int i = 10; i < lim + 1; i++) {
		even_sum.push_back(even_sum[i / 10] + even_sum[i % 10]);
		odd_sum.push_back(odd_sum[i / 10] + odd_sum[i % 10]);
		diff.push_back(abs(even_sum[i] - odd_sum[i]));
	}
	extra = 10;
	dp.push_back(0);
	dp.push_back(2);
	dp.push_back(12);

	for (int i = 3; i < 1000001; i++) {
		extra = extra - (2 * diff[i]) + diff[2 * (i - 1)] + (2 * diff[(2 * i) - 1]) + diff[2 * i];
		dp.push_back(dp[i - 1] + extra);
	}
}

int main() {
	precompute();
	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}