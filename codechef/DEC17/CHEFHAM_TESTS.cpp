#include <bits/stdc++.h>
using namespace std;

int main()
{
	srand(0);
	int t, l, r;
	t = 10;		// tests
	l = 10;		// length
	r = 7;		// range

	cout << t << "\n";
	for (int i = 0; i < t; i++) {
		int counts[r + 1];
		memset(counts, 0, sizeof(counts));

		cout << l << "\n";
		for (int j = 0; j < l; j++) {
			int tmp = (rand() % r) + 1;
			while (counts[tmp] == 2) {
				tmp = (rand() % r) + 1;
			}
			counts[tmp]++;

			cout << tmp << " ";
		}
		cout << "\n";
	}

	return 0;
}