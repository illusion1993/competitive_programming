#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll sumDiv(int a, int b) {
	// cout << "called for " << a << ", " << b << ": \n";
	if (a == 1 || b == 1) return 1;
	ll sum = 0;
	int a_m = min(a, b), b_m = max(a, b);
	for (int i = 1; i <= sqrt(a_m); i++) {
		if (a_m % i == 0) {
			if (b_m % i == 0) sum = (sum + i) % 1000000007;
			if (i != (a_m / i) && b_m % (a_m / i) == 0) sum = (sum + (a_m / i)) % 1000000007;
		}
	}
	// cout << sum << "\n";
	return sum;
}

ll sumDiv2(ll n) {
	ll fact[n + 1], nc2[n + 1], sum = 0;
	fact[0] = 1;
	nc2[0] = nc2[1] = 0;
	for (ll i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
	for (ll i = 2; i <= n; i++) nc2[i] = fact[i] / (fact[2] * fact[i - 2]);
	for (ll i = 1; i <= n; i++) {
		sum += (i * (nc2[n / i] + (n / i)));
	}
	return sum;
}

void analyze(int n) {
	for (int i = 1; i < n; i++) {
		cout << i << "." << n / i << "C2 + " << i * (n / i) << endl;
	}
}

int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);

	ll n;
	ll sum = 0;
    cin >> n;
    analyze(n);
    // for (int i = 1; i <= n; i++) {
    // 	for (int j = i; j <= n; j++) {
    // 		sum = (sum + sumDiv(i, j)) % 1000000007;
    // 	}
    // }
    // cout << sum << endl << sumDiv2(n);

    return 0;
}
