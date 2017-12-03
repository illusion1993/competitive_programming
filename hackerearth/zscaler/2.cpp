#include <bits/stdc++.h>

int main() {
	int n, d, sum, play, arr[100000], dp[100000];
	memset(dp, 0, sizeof(dp));
	
	std::cin >> n >> d;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];

	sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum >= d) {
			dp[i] = sum / d;
			sum %= d;
		}
	}
	play = sum = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i])
			play = std::max(play, i - sum);
		sum += dp[i];
	}
	std::cout << play + 1;

	return 0;
}