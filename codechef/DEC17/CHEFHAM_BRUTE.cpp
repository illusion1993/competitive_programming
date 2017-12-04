#include <bits/stdc++.h>
using namespace std;

int max_dist, t, n, arr[100000];
vector<int> ans;

int hamming(vector<int> &v) {
	int dist = 0;
	for (int i = 0; i < n; i++)
		dist += (v[i] != arr[i]);
	return dist;
}

void start(vector<int> &v, vector<int> &done) {
	if (v.size() == n) {
		int h = hamming(v);
		if (h > max_dist) {
			max_dist = h;
			ans.clear();
			for (int i = 0; i < n; i++)
				ans.push_back(v[i]);
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!done[i]) {
			v.push_back(arr[i]);
			done[i] = 1;
			start(v, done);
			v.pop_back();
			done[i] = 0;
		}
	}
}

void solve() {
	
}

int main() {
	std::ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> t;
	while (t--) {
		max_dist = -1;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		vector<int> temp;
		vector<int> done(n, 0);
		start(temp, done);
		for (int i = 0; i < n; i++)
			cout << ans[i] << " ";
		cout << " | " << max_dist << "\n";
	}

	return 0;
}