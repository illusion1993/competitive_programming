#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a[1000];
	double pl = 0, ps = 0, nl, ns;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i < 300) {
			pl += a[i];
			if (i >= 240) ps += a[i];
		}
	}

	for (int i = 300; i < n; i++) {
		nl = pl - a[i - 300];
		ns = ps - a[i - 60];

		if (
			(
				(round((ps / 60.00) * 100) > round((pl / 300.00) * 100)) 
				&& 
				(round((ns / 60.00) * 100) <= round((nl / 300.00) * 100))
			) ||
			(
				(round((ps / 60.00) * 100) < round((pl / 300.00) * 100)) 
				&& 
				(round((ns / 60.00) * 100) >= round((nl / 300.00) * 100))
			) ||
			(
				(round((ps / 60.00) * 100) == round((pl / 300.00) * 100)) 
				&& 
				(round((ns / 60.00) * 100) != round((nl / 300.00) * 100))
			)
		) {
			cout << i + 1 << " " << round((ns / 60.00) * 100) / 100 << " " << round((ns / 300.00) * 100) / 100 << "\n";
		}


		pl = nl;
		ps = ns;
	}

	return 0;
}