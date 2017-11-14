#include <bits/stdc++.h>
using namespace std;

int t, n, p;
string s;

void flip(int index) {
	if (index < 0 || index >= n || s[index] == 'b') return;
	s[index] = 'b';
	flip(n - index - 1);
	flip(index - p);
	flip(index + p);
}

int main() {
	cin >> t;
	while (t--) {
		int a_c = 0;
		s = "";
		cin >> n >> p;
		for (int i = 0; i < n; i++) s += 'a';
		
		flip(1);

		for (int i = 0; i < n; i++) if (s[i] == 'a') a_c++;
		if (a_c == 0 || a_c == n) cout << "impossible\n";
		else cout << s << "\n";
	}

	return 0;
}