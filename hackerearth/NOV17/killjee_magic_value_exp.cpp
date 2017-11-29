#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long lim = 2000000;

long long k;

struct Value {
	long long multiplier, remainder;
	Value() {
		multiplier = remainder = 0;
	}
	Value(long long multiplier, long long remainder) : multiplier(multiplier), remainder(remainder) {}
	Value(long long x) {
		multiplier = (x / k) % MOD;
		remainder = x % k;
	}
};

Value operator + (const Value & a, const Value & b) {
	long long carry = (a.remainder + b.remainder) / k;
	return Value((a.multiplier + b.multiplier + carry) % MOD, (a.remainder + b.remainder) % k);
}

Value operator * (const Value & a, const Value & b) {
	long long m;
	m = ((((long long)a.multiplier * (long long)b.multiplier) % MOD) * k) % MOD;
	m =  (m + (((long long)a.multiplier * (long long)b.remainder) % MOD)) % MOD;
	m = (m + (((long long)a.remainder * (long long)b.multiplier) % MOD)) % MOD;
	m = (m + (((long long)a.remainder * (long long)b.remainder) / k)) % MOD;
	return Value(m, (a.remainder * b.remainder) % k);
}

int main() {
	int t, l, r;
	cin >> t;

	while (t--) {
		cin >> l >> r >> k;
		
		Value fib0(0), fib1(1), fac(1), ret(0);

		for (int i = 1; i <= r; i++) {
			Value fib = fib0 + fib1, num(i);
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