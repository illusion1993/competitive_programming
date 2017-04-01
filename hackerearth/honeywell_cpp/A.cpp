#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n, m, last_row[1000], mr_max, mc_max, col_cont[1000], row_cont, tmp;
	cin >> t;

	while(t--) {
		mr_max = 1;
		mc_max = 1;
		cin >> n >> m;
		
		for (int row = 0; row < n; row++) {
			//row_cont = 1;
			for (int col = 0; col < m; col++) {
				cin >> tmp;
				//if (!row) col_cont[col] = 1;
				
				if (col && last_row[col - 1] == tmp) {
					row_cont++;
					mr_max = max(mr_max, row_cont);
				}
				else row_cont = 1;

				if (row && last_row[col] == tmp) {
					col_cont[col]++;
					mc_max = max(mc_max, col_cont[col]);
				}
				else col_cont[col] = 1;
				
				last_row[col] = tmp;
			}
		}
		cout << mr_max * mc_max << "\n";
	}
	return 0;
}