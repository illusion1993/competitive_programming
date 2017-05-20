#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t, n, tmp;
	vector<int> v;
	bool okay;

	cin >> t;
	while(t--) {
		v.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			v.push_back(tmp);
		}
		okay = (v[0] == 1);
		for (int i = 0; i <= n / 2 && okay; i++) {
			if (v[i] != v[n - 1 - i]) okay = false;
			if (i && v[i] != v[i-1] + 1) okay = false;
		}
		cout << ((okay) ? "yes\n" : "no\n");
	}

	return 0;
}