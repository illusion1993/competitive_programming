#include <bits/stdc++.h>
using namespace std;

int t, x, y, z, a, b, c, d;
vector<string> ans_ops;

void process(vector<string> &ops, int xx, int yy, int zz, int cost) {
	if (xx > x || yy > y || zz > z)
		return;

	if (xx == x && yy == y && zz == z) {
		if (cost < d) {
			d = cost;
			ans_ops.clear();
			for (int i = 0; i < ops.size(); i++)
				ans_ops.push_back(ops[i]);
		}
		return;
	}

	xx += 1;
	ops.push_back("ax");
	cost += a;
	process(ops, xx, yy, zz, cost);
	xx -= 1;
	ops.pop_back();
	cost -= a;

	yy += 1;
	ops.push_back("ay");
	cost += a;
	process(ops, xx, yy, zz, cost);
	yy -= 1;
	ops.pop_back();
	cost -= a;

	zz += 1;
	ops.push_back("az");
	cost += a;
	process(ops, xx, yy, zz, cost);
	zz -= 1;
	ops.pop_back();
	cost -= a;

	xx += 1;
	yy += 1;
	ops.push_back("bxy");
	cost += b;
	process(ops, xx, yy, zz, cost);
	xx -= 1;
	yy -= 1;
	ops.pop_back();
	cost -= b;

	xx += 1;
	zz += 1;
	ops.push_back("bxz");
	cost += b;
	process(ops, xx, yy, zz, cost);
	xx -= 1;
	zz -= 1;
	ops.pop_back();
	cost -= b;

	yy += 1;
	zz += 1;
	ops.push_back("byz");
	cost += b;
	process(ops, xx, yy, zz, cost);
	yy -= 1;
	zz -= 1;
	ops.pop_back();
	cost -= b;

	xx += 1;
	yy += 1;
	zz += 1;
	ops.push_back("c");
	cost += c;
	process(ops, xx, yy, zz, cost);
	xx -= 1;
	yy -= 1;
	zz -= 1;
	ops.pop_back();
	cost -= c;
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