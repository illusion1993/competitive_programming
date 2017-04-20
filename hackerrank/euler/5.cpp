#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXRANGE 40

vector<int> factors[MAXRANGE];
void segSieve() {
	int vals[MAXRANGE];
	for (int i = 0; i < MAXRANGE; i++) vals[i] = i + 1;

	for (int i = 1; i < MAXRANGE; i++) {
		if (vals[i] != 1) {
			int fac = vals[i];
			factors[i].push_back(fac);
			for (int j = i + fac; j < MAXRANGE; j += fac) {
				while(vals[j] % fac == 0) {
					vals[j] /= fac;
					factors[j].push_back(fac);
				}
			}
		}
	}
}

int maxCount[41];
void findMaxCounts(int n) {
	memset(maxCount, 0, sizeof(maxCount));
	for (int i = 0; i < n; i++) {
		int prev = 0, c = 0;
		for (int j = 0; j < factors[i].size(); j++) {
			if (factors[i][j] != prev) {
				maxCount[prev] = max(maxCount[prev], c);
				c = 0;
				prev = factors[i][j];
			}
			c++;
		}
		maxCount[prev] = max(maxCount[prev], c);
	}
}

ll findMultiple(int n) {
	ll ans = 1;
	for (int i = 2; i <= n; i++) {
		ans *= (ll)pow(i, maxCount[i]);
	}
	return ans;
}

int main(){
	std::ios::sync_with_stdio(false);
    cin.tie(0);
	segSieve();
	int t, n;
    cin >> t;
    while(t--) {
    	cin >> n;
    	findMaxCounts(n);
    	cout << findMultiple(n) << "\n";
    }
    return 0;
}