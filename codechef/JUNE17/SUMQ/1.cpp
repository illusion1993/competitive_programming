#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

map<int, vector<bool> > v;

ll count_f() {
	ll ans = 0, s0 = 0, s2 = 0, c0 = 0, c2 = 0, dp1 = 0, dp2 = 0, dp3 = 0;
	for (map<int, vector<bool> >::iterator it = v.begin(); it != v.end(); it++) {
		// cout << "- " << it -> first << "\n";

		if (it -> second[0]) {
			dp1 = (dp1 + c2) % M;
			dp2 = (dp2 + s2) % M;
			dp2 = (dp2 + ((c2 * it -> first) % M)) % M;
			dp3 = (((s2 * it -> first) % M) + dp3) % M;
		}
		if (it -> second[2]) {
			dp1 = (dp1 + c0) % M;
			dp2 = (dp2 + s0) % M;
			dp2 = (dp2 + ((c0 * it -> first) % M)) % M;
			dp3 = (((s0 * it -> first) % M) + dp3) % M;
		}
		
		if (it -> second[0]) { c0++; s0 = (s0 + it -> first) % M; }
		if (it -> second[2]) { c2++; s2 = (s2 + it -> first) % M; }
		
		if (it -> second[0] && it -> second[2]) {
			dp1 = (dp1 + 1) % M;
			dp2 = (dp2 + ((2 * it -> first) % M)) % M;
			dp3 = (dp3 + ((it -> first * it -> first) % M)) % M;
		}

		// cout << "At " << it -> first << ", dp1 = " << dp1 << " dp2 = " << dp2 << ", dp3 = " << dp3 << "\n";
		if (it -> second[1]) {
			ll x, x_sq;
			x = it -> first % M;
			x_sq = (x * x) % M;

			ans = (ans + ((x_sq * dp1) % M)) % M;
			ans = (((dp2 * x) % M) + ans) % M;
			ans = (ans + dp3) % M;
			// cout << "At " << it -> first << " ans became " << ans << "\n";
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    // ifstream cin("tc.txt");
    // ofstream cout("1_out.txt");
    
    int t, p, q, r, tmp;
    vector<bool> b(3, false);
    cin >> t;

    while(t--) {
    	v.clear();
    	cin >> p >> q >> r;
    	for (int i = 0; i < p; i++) {
    		cin >> tmp;
    		if (!v.count(tmp)) v[tmp] = b;
    		v[tmp][0] = true;
    	}
		for (int i = 0; i < q; i++) {
    		cin >> tmp;
    		if (!v.count(tmp)) v[tmp] = b;
    		v[tmp][1] = true;
    	}
		for (int i = 0; i < r; i++) {
			cin >> tmp;
			if (!v.count(tmp)) v[tmp] = b;
    		v[tmp][2] = true;
		}
		cout << count_f() << "\n";
    }

    return 0;
}

/*

3
8 5 7
5 6 8 9 11 14 15 20
5 9 10 17 20
5 7 8 9 10 14 19
2 1 2
6 8
9
7 8
4 6 5
5 7 11 17
6 7 11 15 16 18
5 10 11 15 17

*/