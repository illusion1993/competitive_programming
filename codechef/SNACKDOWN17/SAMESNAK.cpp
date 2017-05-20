#include<bits/stdc++.h>
using namespace std;

bool is_horiz(int x1, int y1, int x2, int y2) {
	return (y1 == y2);
}

bool point_between(int x1, int y1, int x2, int y2, int xp, int yp) {
	if (is_horiz(x1, y1, x2, y2)) {
		return ((yp == y1) && (xp >= min(x1, x2)) && (xp <= max(x1, x2)));
	}
	else {
		return ((xp == x1) && (yp >= min(y1, y2)) && (yp <= max(y1, y2)));
	}
}

int main(int argc, char const *argv[])
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	
	int t, x11, y11, x12, y12, x21, y21, x22, y22;
	cin >> t;

	while(t--) {
		bool ans = false;
		cin >> x11 >> y11 >> x12 >> y12 >> x21 >> y21 >> x22 >> y22;
		if (is_horiz(x11, y11, x12, y12) == is_horiz(x21, y21, x22, y22)) {
			if (point_between(x11, y11, x12, y12, x21, y21) || point_between(x11, y11, x12, y12, x22, y22)) ans = true;
		}
		else {
			if (
				(x11 == x21 && y11 == y21) || (x12 == x21 && y12 == y21) ||
				(x11 == x22 && y11 == y22) || (x12 == x22 && y12 == y22)
				) ans = true;
		}
		cout << ((ans) ? "yes\n" : "no\n");
	}

	return 0;
}