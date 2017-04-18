#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXVAL 1000000000000

vector<int> primes;
void findPrimes(ll x) {
    int n = sqrt(x) + 1;
    bool sieve[n];
    memset(sieve, 0, sizeof(sieve));

    for (int i = 3; i < n; i += 2) {
        if (!sieve[i]) {
            for (int j = 3; i*j < n; j += 2) {
                sieve[i*j] = 1;
            }
        }
    }

    primes.push_back(2);
    for (int i = 3; i < n; i += 2) if (!sieve[i]) primes.push_back(i);
}

ll largestPF(ll n) {
	ll ans = 1;
	int pos = 0, lim = sqrt(n);
	while(primes[pos] <= lim && pos < primes.size()) {
		while(n % primes[pos] == 0) {
			n /= primes[pos];
		}
		if (n == 1) return primes[pos];
		pos++;
	}
	return n;
}

int main(){
    findPrimes(MAXVAL);
    int t;
    ll n;
    cin >> t;
    while(t--) {
    	cin >> n;
    	cout << largestPF(n) << endl;
    }
    return 0;
}