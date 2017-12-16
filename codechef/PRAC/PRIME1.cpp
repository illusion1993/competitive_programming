#include <bits/stdc++.h>
using namespace std;

vector<int> primes;

void prep() {
	bool comp[100000];
	memset(comp, 0, sizeof(comp));
	comp[0] = 1;
	comp[1] = 1;

	for (int i = 2; i * i <= 100000; i++) {
		if (!comp[i]) {
			for (int j = i + i; j < 100000; j += i)
				comp[j] = 1;
		}
	}
	for (int i = 0; i < 100000; i++)
		if (!comp[i])
			primes.push_back(i);
}

void findPrimes(int m, int n) {
	bool comp[n - m + 1];
	memset(comp, 0, sizeof(comp));

	int p = 0;
	while (primes[p] * primes[p] <= n) {
		int i = (m % primes[p] == 0) ? 0 : primes[p] - (m % primes[p]);
		while (i < n - m + 1) {
			if (m + i != primes[p]) {
				comp[i] = 1;
				// cout << "Prime " << primes[p] << " marked " << m + i << " as multiple\n";
			}
			i += primes[p];
		}
		p++;
	}
	for (int i = 0; i < n - m + 1; i++)
		if (!comp[i] && m + i >= 2)
			cout << m + i << "\n";
}

int main() {
	prep();

	int t, m, n;
	cin >> t;

	while (t--) {
		cin >> m >> n;
		findPrimes(m, n);
		cout << "\n";
	}

	return 0;
}