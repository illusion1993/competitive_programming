#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXRANGE 1000000

vector<int> primes;
void findPrimes() {
	bool sieve[MAXRANGE + 1];
	memset(sieve, 0, sizeof(sieve));
	for (int i = 2; i <= MAXRANGE; i++) {
		if (!sieve[i]) {
			primes.push_back(i);
			for (int j = i + i; j <= MAXRANGE; j += i) sieve[j] = 1;
		}
	}
}

ll primeSumTill(int n) {
	ll sum = 0;
	for (int i = 0; i < primes.size() && primes[i] <= n; i++) 
		sum += primes[i];
	return sum;
}

int main(){
	std::ios::sync_with_stdio(false);
    cin.tie(0);
    findPrimes();
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		cout << primeSumTill(n) << "\n";
	}
    return 0;
}