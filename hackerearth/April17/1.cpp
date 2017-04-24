#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n, ammo;
	bool a;
	cin >> t;

	while(t--) {
		cin >> ammo >> n;
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (ammo) {
				ammo = (a) ? ammo + 2 : ammo - 1;
				if (!ammo) {
					if (i == n - 1) cout << "Yes 0\n";
					else cout << "No " << i + 1 << "\n";
				}
			}
		}
		if (ammo) cout << "Yes " << ammo << "\n";
	}
	return 0;
}