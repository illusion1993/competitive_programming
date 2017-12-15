#include <bits/stdc++.h>
using namespace std;

map<long long, long long> memo;

long long get_max(long long n) {
	if (memo.count(n))
		return memo[n];

	if (n <= 2)
		return n;

	long long m = max(n, get_max(n / 2) + get_max(n / 3) + get_max(n / 4));
	memo[n] = m;
	
	return m;
}

int main() {
	long long n;
	while (!cin.eof()) {
		cin >> n;
		cout << get_max(n) << "\n";
	}

	return 0;
}