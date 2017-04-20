#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXRANGE 10000

ll mulTill[MAXRANGE + 1];
void precompute() {
	mulTill[0] = 0;
	for (int i = 1; i <= MAXRANGE; i++) {
		ll sum = 0;
		for (int j = 1; j < i; j++) sum += (ll)2 * (ll)i * (ll)j;
		mulTill[i] = mulTill[i - 1] + sum;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
    cin.tie(0);
	precompute();
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		cout << mulTill[n] << "\n";
	}
    return 0;
}