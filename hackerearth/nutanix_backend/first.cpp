#include <bits/stdc++.h>
using namespace std;

map< int, int > covered;
int n, pos, stock, car_pos, car_fuel, refuel_count;

void add_pump(int stock) {
	if (covered[stock]) covered[stock]++;
	else covered[stock] = 1;
}
void refuel() {
	if (covered.size()) {
		int stock = covered.rbegin() -> first;
		car_fuel += stock;
		refuel_count++;
		covered[stock]--;
		if (!covered[stock]) covered.erase(stock);
	}
}

int main () {
	refuel_count = 0;
	vector< pair<int, int> > pumps;

	cin >> n;
	pumps.push_back(make_pair(0, 0));
	for (int i = 0; i < n; i++) {
		cin >> pos >> stock;
		pumps.push_back(make_pair(pos, stock));
	}
	cin >> car_pos >> car_fuel;

	sort(pumps.begin(), pumps.end());
	while (pumps.back().first > car_pos) pumps.pop_back();

	int crossed = pumps.size() - 1;
	bool possible = true;

	while (crossed >= 0 && possible) {
		while (crossed >= 0 && car_pos - pumps[crossed].first <= car_fuel) {
			add_pump(pumps[crossed].second);
			crossed--;
		}

		if (crossed >= 0) {
			while (car_fuel < car_pos - pumps[crossed].first && covered.size())
				refuel();
			if (car_fuel < car_pos - pumps[crossed].first)
				possible = false;
		}
	}
	if (possible) cout << refuel_count;
	else cout << "-1";
}