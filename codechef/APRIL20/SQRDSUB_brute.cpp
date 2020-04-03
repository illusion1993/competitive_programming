//
// Created by Vikram Singh Rathore
//

#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    
    int t, n;
    ll ans;
    cin >> t;

    while (t--) {
    	ans = 0;
    	cin >> n;
    	vector<ll> arr(n);
    	for (int i = 0; i < n; i++) cin >> arr[i];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				ll mult = 1;
				for (int k = j; k <= i; k++) {
					mult *= arr[k];
				}
				if (mult % 2 == 1 || mult % 4 == 0) ans++;
			}
		}
		cout << ans << "\n";
    }

    return 0;
}