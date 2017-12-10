#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> arr;

int main() {
	
	cin >> n >> q;
	int a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr.push_back(a);
	}

	for (int i = 0; i < q; i++) {
		cin >> a >> b >> c;
		if (a == 1)
			arr[b - 1] = c;
		else {
			int count = 0, p = 0;
			for (int i = 0; i < b; i++) {
				p ^= arr[i];
				if (p == c)
					count++;
			}
			cout << count << "\n";
		}
	}

	return 0;
}