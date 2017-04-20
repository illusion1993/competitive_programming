#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXRANGE 200000
#define MAXREQUIRED 10000

vector<int> primes;
void findPrimes() {
	bool sieve[MAXRANGE];
	memset(sieve, 0, sizeof(sieve));
	for (int i = 2; i < MAXRANGE && primes.size() <= MAXREQUIRED; i++) {
		if (!sieve[i]) {
			primes.push_back(i);
			for (int j = i + i; j < MAXRANGE; j += i) sieve[j] = 1;
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
    cin.tie(0);
	findPrimes();
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		cout << primes[n - 1] << "\n";
	}
    return 0;
}