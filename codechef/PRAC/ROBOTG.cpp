#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(false);
    cin.tie(0);

	int t, n, m, hpos, vpos, rmax, lmax, umax, dmax;
	string s;

	cin >> t;
	while(t--){
		hpos = vpos = 0;
		rmax = lmax = umax = dmax = 0;
		cin >> n >> m >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'L') hpos--;
			else if (s[i] == 'R') hpos++;
			else if (s[i] == 'U') vpos++;
			else vpos--;

			lmax = min(lmax, hpos);
			rmax = max(rmax, hpos);
			umax = max(umax, vpos);
			dmax = min(dmax, vpos);
		}

		cout << (((rmax - lmax + 1 <= m) && (umax - dmax + 1 <= n)) ? "safe\n" : "unsafe\n");
	}
	return 0;
}
