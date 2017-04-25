#include<bits/stdc++.h>
using namespace std;
#define ll long long

unordered_map< int, unordered_map< int, unordered_map< int, int > > > pm, kpm;

void setpm(int n, int power, int m, int val) {
	if (pm.count(n)) {
		if (pm[n].count(power)) {
			pm[n][power][m] = val;
		}
		else {
			unordered_map< int, int > M;
			M[m] = val;
			pm[n][power] = M;
		}
	}
	else {
		unordered_map< int, unordered_map< int, int > > MM;
		unordered_map< int, int > M;
		M[m] = val;
		MM[power] = M;
		pm[n] = MM;
	}
}

int powerMod(int n, int power, int m, bool cache) {
	// cout << "Called for powerMod of " << n << "^" << power << " % " << m << "\n";
	if (n >= m) return powerMod(n % m, power, m, cache);
	if (power == 1) return n % m;
	else if (power == 0) return 1;

	if (pm.count(n) && pm[n].count(power) && pm[n][power].count(m)) {
		// cout << "(Found in cache) " << pm[n][power][m] << "\n";
		return pm[n][power][m];
	}

	int ans = powerMod((powerMod(n * n, power / 2, m, false) * powerMod(n, power % 2, m, false)), 1, m, false);
	if (cache) {
		// cout << "(Saving in cache) " << ans << "\n";
		setpm(n, power, m, ans);
	}
	
	return ans;
}

int kthPowerMod(int n, int k, int m) {
	if (k == 1) return n % m;
	
	int f = n % m, count = 1, pos;
	while(powerMod(n, count + 1, m, true) != f) count++;
	pos = kthPowerMod(n, k - 1, count);

	vector<int> powerMods;
	powerMods.push_back(f);
	int power = 2, newPowerMod = powerMod(n, 2, m, false);

	while(newPowerMod != powerMods[0]) {
		powerMods.push_back(newPowerMod);
		power++;
		newPowerMod = powerMod(n, power, m, false);
	}

	if (pos) return powerMods[pos - 1];
	return powerMods.back();
}

int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);

	int t, n, k, m;
    cin >> t;
    while(t--) {
    	cin >> n >> k >> m;
    	cout << kthPowerMod(n, k, m) << "\n";
    }

    return 0;
}
