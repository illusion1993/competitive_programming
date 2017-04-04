#include<bits/stdc++.h>
using namespace std;
int n, c;

bool is_magic(vector<vector<int> > a) {
	return true;
}

void printvector(vector<vector<int> > a) {
	cout << "Asked for vector: \n";
	for (int i = 0; i < n*n; i++) {
		for (int j = 0; j < n*n; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	c++;
}

void fill(vector<vector<int> > a, int pos) {
	if (pos == n*n*n*n && is_magic(a)) //printvector(a);
	{}
	else {
		int r = pos / (n * n), c = pos % (n * n);
		int rg = r / n, cg = c / n;

		cout << "For r, c = " << r << ", " << c << ": rg, cg = " << rg << ", " << cg << endl;

		for (int i = 1; i <= n*n; i++) {
			// i is number we want to fill
			bool is_ok = true;
			for (int j = 0; j < n*n; j++) {
				if ((a[r][j] == i) || (a[j][c] == i)) {
					is_ok = false;
					break;
				}
			}
			// for (int x = rg * n; x < (rg+1) * n; x++) {
			// 	for (int y = cg * n; x < (cg+1) * n; y++) {
			// 		if (a[rg][cg] == i) {
			// 			is_ok = false;
			// 			break;
			// 		}
			// 	}
			// }

			if (is_ok) {
				a[r][c] = i;
				fill(a, pos + 1);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	cin >> n;
	c = 0;
	vector<vector<int> > a(n*n, vector<int>(n*n, 0));
	fill(a, 0);
	cout << c;
	return 0;
}