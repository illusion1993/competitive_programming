#include <bits/stdc++.h>
using namespace std;
#define lim 100

int t, x, y, z, a, b, c, dp[lim + 1][lim + 1][lim + 1];

void process() {
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			for (int k = 0; k <= z; k++) {
				if (i == 0 && j == 0 && k == 0)
					dp[i][j][k] = 0;
				else {
					int m = INT_MAX;
					if (i > 0)
						m = min(m, dp[i - 1][j][k] + a);
					if (j > 0)
						m = min(m, dp[i][j - 1][k] + a);
					if (k > 0)
						m = min(m, dp[i][j][k - 1] + a);
					if (i > 0 && j > 0)
						m = min(m, dp[i - 1][j - 1][k] + b);
					if (j > 0 && k > 0)
						m = min(m, dp[i][j - 1][k - 1] + b);
					if (i > 0 && k > 0)
						m = min(m, dp[i - 1][j][k - 1] + b);
					if (i > 0 && k > 0 && j > 0)
						m = min(m, dp[i - 1][j - 1][k - 1] + c);
					dp[i][j][k] = m;
				}
			}
		}
	}
}

int main() {
	cin >> t;
	while (t--) {
		cin >> x >> y >> z >> a >> b >> c;
		memset(dp, 0, sizeof(dp));
		process();
		cout << dp[x][y][z] << "\n";
	}
	return 0;
}