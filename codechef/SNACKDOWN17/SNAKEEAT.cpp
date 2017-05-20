#include<bits/stdc++.h>
using namespace std;

int bin_sear(vector<int> &v, int x) {
	if (x > v.back()) return -1;
	else if (x < v[0]) return 0;
	int begin = 0, end = v.size() - 1;

	while(1) {
		int pos = (begin + end) / 2;
		if (x <= v[pos] && x > v[pos - 1]) return pos;
		else if (x > v[pos] && x <= v[pos + 1]) return pos + 1;
		if (x > v[pos]) begin = pos + 1;
		else end = pos - 1;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t, n, q, tmp, count;
	vector<int> v;

	cin >> t;
	while(t--) {
		v.clear();
		cin >> n >> q;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());

		while(q--) {
			cin >> tmp;
			int eaten = count = 0, pos;
			pos = bin_sear(v, tmp);
			count = (pos >= 0) ? n - pos : 0;

			for (int i = pos - 1; i >= 0; i--) {
				eaten += tmp - v[i];
				if (eaten <= i) count++;
				else break;
			}
			cout << count << "\n";
		}
	}

	return 0;
}