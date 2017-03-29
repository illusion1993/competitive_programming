#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a[100000], m;
	long long max_f = LLONG_MIN, f;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n - 1; j++) {
			f = 0;
			m = 1;
			for (int k = i; k <= j; k++) {
				f += m * abs(a[k] - a[k + 1]);
				m *= -1;
			}
			if (f > max_f) cout << "from " << i << " to " << j << endl;
			max_f = max(f, max_f);
		}
	}
	cout << max_f;

	return 0;
}