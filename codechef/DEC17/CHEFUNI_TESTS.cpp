#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(0);
	int t, coord_range, cost_range;
	t = 2;
	coord_range = 10;
	cost_range = 8;

	cout << t << "\n";
	for (int i = 0; i < t; i++) {
		cout << (rand() % coord_range) + 1 << " " << (rand() % coord_range) + 1 << " " << (rand() % coord_range) + 1 << " ";
		cout << (rand() % cost_range) + 1 << " " << (rand() % cost_range) + 1 << " " << (rand() % cost_range) + 1 << "\n";
	}


	return 0;
}