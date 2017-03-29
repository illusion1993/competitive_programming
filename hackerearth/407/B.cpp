#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	map<int, bool> bad;
	int d, l, m, tmp, n = 0;
	long long a;

	cin >> a >> d >> l >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		bad[tmp] = true;
	}

	if (d == 0) {
		if (bad.count(a)) n = 0;
		else n = 1;
		
		if (!bad.count(0)) {
			cout << "inf";
			return 0;
		}
	}
	else if (d == 1) {
		n = 0;
		if (bad.count(a) == 0 && abs(a) <= l) {
			cout << "inf";
			return 0;
		}
	}
	else if (d == -1) {
		n = 0;
		if ((bad.count(a) == 0 || bad.count(-1 * a) == 0) && (abs(a) <= l)) {
			cout << "inf";
			return 0;
		}
	}
	else {
		while(abs(a) <= l) {
			if (bad.count(a) == 0) n++;
			a *= d;
		}
	}
	cout << n;

	return 0;
}