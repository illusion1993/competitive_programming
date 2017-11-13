#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	string s;

	cin >> n;
	while (n--) {
		int prev = -1, previndex = -1, ac = 0, bc = 0;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'A') {
				if (prev == 0) ac += i - previndex - 1;
				ac++;
				prev = 0;
				previndex = i;
			}
			if (s[i] == 'B') {
				if (prev == 1) bc += i - previndex - 1;
				bc++;
				prev = 1;
				previndex = i;
			}
		}
		cout << ac << " " << bc << "\n";
	}

	return 0;
}