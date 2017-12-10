#include <bits/stdc++.h>
using namespace std;

int t, n, dist;
vector<int> arr;
vector<int> carr;
vector<bool> shifted;

void shuffle() {
	for (int i = 0; i < n; i++) {
		if (!shifted[i]) {
			for (int j = 0; j < n; j++) {
				if (arr[j] != arr[i] && carr[i] != arr[j] && carr[j] != arr[i]) {
					int x = arr[j];
					arr[j] = arr[i];
					arr[i] = x;
					shifted[i] = 1;
					shifted[j] = 1;
				}
			}
		}
	}
	dist = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] != carr[i])
			dist++;
	}
}

int main() {
	cin >> t;
	while (t--) {
		arr.clear();
		carr.clear();
		shifted.clear();
		cin >> n;

		int tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			arr.push_back(tmp);
			carr.push_back(tmp);
			shifted.push_back(0);
		}
		shuffle();

		cout << dist << "\n";
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}
	return 0;
}