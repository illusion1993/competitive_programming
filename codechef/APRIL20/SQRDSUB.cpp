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
    	ll arr;
    	ll a, b, c, dp0, dp1, dp2;

    	for (int i = 0; i < n; i++) {
    		cin >> arr;
    		dp0 = dp1 = dp2 = 0;

    		if (arr % 2) {
    			dp0 = 1;
    			if (i) {
    				dp0 += a;
    				dp1 = b;
    				dp2 = c;
    			}
    		}

    		else if (arr % 4 == 0) {
    			dp2 = 1;
    			if (i) {
    				dp2 += a + b + c;
    			}
    		}

    		else {
    			dp1 = 1;
    			if (i) {
    				dp1 += a;
    				dp2 += b + c;
    			}
    		}

    		ans += dp0;
    		ans += dp2;
    		a = dp0;
    		b = dp1;
    		c = dp2;
    	}
    	cout << ans << "\n";
		
    }

    return 0;
}