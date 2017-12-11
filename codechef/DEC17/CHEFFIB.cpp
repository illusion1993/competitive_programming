#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define lim 300000

vector<int> fib;
void make_fib() {
	fib.push_back(0);
	fib.push_back(1);
	for (int i = 2; i <= lim; i++) {
		fib.push_back((fib[i - 1] + fib[i - 2]) % mod);
	}
}

int f(int a, int b, int d) {
	if (d == 0)
		return a % mod;
	return (((fib[d - 1] * a) % mod) + ((fib[d] * b) % mod)) % mod;
}

vector< vector<int> > nodes;
vector<int> values;

void process(int index, int max_dist, int a, int b, int d, int prev) {
	values[index] = (values[index] + f(a, b, d)) % mod;
	if (d < max_dist) {
		for (int i = 0; i < nodes[index].size(); i++) {
			if (nodes[index][i] != prev) {
				process(nodes[index][i], max_dist, a, b, d + 1, index);
			}
		}
	}
}

int main() {
	make_fib();

	int t, n, q, u, v, w, x, y;
	cin >> t;

	while (t--) {
		cin >> n >> q;
		nodes.clear();
		values.clear();

		vector<int> p;
		for (int i = 0; i < n; i++) {
			nodes.push_back(p);
			values.push_back(0);
		}
		
		for (int i = 0; i < n - 1; i++) {
			cin >> u >> v;
			nodes[u].push_back(v);
			nodes[v].push_back(u);
		}

		for (int i = 0; i < q; i++) {
			cin >> u;
			if (u == 1) {
				cin >> v >> w >> x >> y;
				process(v - 1, w, x, y, 0, -1);
			}
			else {
				cin >> v;
				cout << values[v - 1] << "\n";
			}
		}
	}

	return 0;
}