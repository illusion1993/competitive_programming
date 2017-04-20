#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<ll, ll> > testcases;

ll findMaxProd(ll n) {
	ll maxProd = -1;
	for (ll a = 1; a <= n / 2; a++) {
		for (ll b = a; b <= n / 2; b++) {
			ll c = n - a - b;
			if ((a && b && c) && (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a)) 
				maxProd = max(maxProd, a*b*c);
		}
	}
	return maxProd;
}

ll findMaxProd1(ll n) {
	ll maxProd = -1, prod;
	for (ll c = 5; c < n / 2; c++) {
		ll d, d_root;
		d = (4 * (n - c) * (n - c) - (8 * (((n - c) * (n - c)) - (c*c))));
		d_root = sqrt(d);
		if (d >= 0 && d_root * d_root == d) {
			maxProd = max((((n * n * c) - (2 * n * c * c)) / 2), maxProd);
		}
	}
	return maxProd;
}

int main(){
	std::ios::sync_with_stdio(false);
    cin.tie(0);
	int t;
	// ll n;
	cin >> t;
	while(t--) {
		// cin >> n;
		ll x, y;
		x = findMaxProd(t);
		y = findMaxProd1(t);
		if (x != y)
			cout << t << ": " << x << ", " << y << "\n";
		else cout << t << ": " << "OK\n";
	}
    return 0;
}