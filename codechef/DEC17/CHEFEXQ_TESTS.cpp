#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(NULL));
	int n, q, lim;
	n = 10;
	q = 10;
	lim = 5;

	cout << n << " " << q << "\n";
	for (int i = 0; i < n; i++)
		cout << (rand() % lim) + 1 << " ";
	cout << "\n";
	for (int i = 0; i < q; i++) {
		int x = (rand() % lim) + 1;
		int y = (rand() % lim) + 1;
		cout << (rand() % 2) + 1 << " " << min(x, y) << " " << max(x, y) << "\n";
	}
	return 0;
}