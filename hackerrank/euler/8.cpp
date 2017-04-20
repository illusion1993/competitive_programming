#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll findMaxProd(string s, int k) {
	ll prod = 1, maxProd = 1;
	for (int i = 0; i < k; i++) {
		prod *= ((ll)s[i] - 48);
		maxProd = prod;
	}
	for (int i = k; i < s.length(); i++) {
		prod = 1;
		for (int j = i - k + 1; j <= i; j++) prod *= ((ll)s[j] - 48);
		maxProd = max(maxProd, prod);
	}
	return maxProd;
}

int main(){
	std::ios::sync_with_stdio(false);
    cin.tie(0);
	int t, n, k;
	string s;
	cin >> t;
	while(t--) {
		cin >> n >> k >> s;
		cout << findMaxProd(s, k) << "\n";
	}
    return 0;
}