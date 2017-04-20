#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll findMaxProd(ll n) {
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
	ll n;
	cin >> t;
	while(t--) {
		cin >> n;
		cout << findMaxProd(n) << "\n";
	}
    return 0;
}