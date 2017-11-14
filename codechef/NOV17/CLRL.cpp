#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, m, last_fall_from, last_rise_from;
	int arr[1000000];

	bool possible;
	cin >> t;

	while (t--) {
		possible = true;
		
		last_fall_from = INT_MAX;
		last_rise_from = INT_MIN;

		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> arr[i];
		if (n > 2) {
			for (int i = 1; i < n && possible; i++) {
				if (arr[i] > arr[i - 1]) {
					if (arr[i] > last_fall_from) possible = false;
					last_rise_from = arr[i - 1];
				}
				else {
					if (arr[i] < last_rise_from) possible = false;
					last_fall_from = arr[i - 1];
				}
			}
		}
		if (possible) cout << "YES\n";
		else cout << "NO\n";
	}


	return 0;
}