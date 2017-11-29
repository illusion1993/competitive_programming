#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int lim = 2000000;

struct Value {
	int multiplier, remainder, k;
	Value(int div) {
		multiplier = remainder = 0;
		k = div;
	}
	Value(int multiplier, int remainder, int div) : multiplier(multiplier), remainder(remainder), k(div) {}
	Value(long long x, int div) {
		k = div;
		multiplier = (x / k) % MOD;
		remainder = (x % k) % MOD;
	}
};

Value operator + (const Value & a, const Value & b) {
	return Value((a.multiplier + b.multiplier + ((a.remainder + b.remainder) / a.k)) % MOD, (a.remainder + b.remainder) % a.k, a.k);
}

Value operator * (const Value & a, const Value & b) {
	int m;
	m = (((a.multiplier * b.multiplier) % MOD) * a.k) % MOD;
	m =  (m + ((a.multiplier * b.remainder) % MOD)) % MOD;
	m = (m + ((a.remainder * b.multiplier) % MOD)) % MOD;
	m = (m + ((a.remainder * b.remainder) % a.k)) % MOD;
	return Value(m, (a.remainder * b.remainder) % a.k, a.k);
}

int main() {
	int t, l, r, k;
	cin >> t;

	while (t--) {
		cin >> l >> r >> k;
		Value fib0(0, k), fib1(1, k), fac(1, k), ret(0, k);
		for (int i = 1; i <= r; i++) {
			Value fib = fib0 + fib1, num(i, k);
			fib0 = fib1;
			fib1 = fib;
			fac = fac * num;
			if (i >= l)
				ret = ret + (fib * fac);
		}
		cout << ret.multiplier << "\n";
	}
	return 0;
}