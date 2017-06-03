#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

vector<ll> a, b, c;

int count_f() {
	int ans = 0;
	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < c.size() && c[j] <= b[i]; j++) {
			for (int k = 0; k < a.size() && a[k] <= b[i]; k++) {
				// cout << "x = " << a[k] << ", y = " << b[i] << ", z = " << c[j] << " : " << (((b[i] + c[j]) % M) * ((b[i] + a[k]) % M)) % M << "\n";
				ans = (((((b[i] + c[j]) % M) * ((b[i] + a[k]) % M)) % M) + ans) % M;
			}
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    // ifstream cin("tc.txt");
    // ofstream cout("brute_out.txt");
    
    int t, p, q, r;
    cin >> t;

    while(t--) {
    	cin >> p >> q >> r;
    	a.clear(); b.clear(); c.clear();
    	a.resize(p); b.resize(q); c.resize(r);
    	for (int i = 0; i < p; i++) cin >> a[i];
		for (int i = 0; i < q; i++) cin >> b[i];
		for (int i = 0; i < r; i++) cin >> c[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		sort(c.begin(), c.end());

		cout << count_f() << "\n";
    }

    return 0;
}
