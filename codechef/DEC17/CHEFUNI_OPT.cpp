#include <bits/stdc++.h>
using namespace std;

int t, x, y, z, a, b, c, d;
vector<string> ans_ops;

void process(vector< pair<int, char> > &ops, int xx, int yy, int zz) {
	vector<int> counts(3, 0);

	while (xx != x || yy != y || zz != z) {
		
	}
}

void prep() {
	vector< pair<int, char> > ops;
	ops.push_back(make_pair(a, 'a'));
	ops.push_back(make_pair(b, 'b'));
	ops.push_back(make_pair(c, 'c'));
	sort(ops.begin(), ops.end());

	process(ops, 0, 0, 0);
}

int main() {
	cin >> t;
	while (t--) {
		d = INT_MAX;
		vector<string> ops;

		cin >> x >> y >> z >> a >> b >> c;
		process(ops, 0, 0, 0, 0);

		for (int i = 0; i < ans_ops.size(); i++)
			cout << ans_ops[i] << " ";
		cout << d << "\n";
	}
	return 0;
}