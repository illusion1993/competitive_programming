//
// Created by Vikram Singh Rathore
//

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define limit 31625

vector<int> getPrimes() {
	vector<int> ans;
	int j;
	bitset<limit + 1> composite(0);
	for (int i = 2; i <= limit; i++) {
		if (!composite[i]) {
			ans.push_back(i);
			j = i + i;
			while (j <= limit) {
				composite[j] = 1;
				j += i;
			}
		}
	}
	return ans;
}

int powersum(ll x, vector<int> &primes) {
	int ptr = 0, ans = 0;
	while (x > 1 && ptr < primes.size() && primes[ptr] < x) {
		while (x % primes[ptr] == 0) {
			x /= primes[ptr];
			ans++;
		}
		ptr++;
	}
	if (x > 1) ans++;
	return ans;
}

int main() {
    vector<int> primes = getPrimes();

    int t;
    ll x, k;
    cin >> t;
    while (t--) {
    	cin >> x >> k;
    	if (powersum(x, primes) >= k) cout << "1\n";
    	else cout << "0\n";
    }
    return 0;
}