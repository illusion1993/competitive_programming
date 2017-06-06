#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int argc, char const *argv[])
{
	int t, n;
	vector<int> v;
	ll ans, tmp, s, c, neg;
	cin >> t;
 
	while(t--) {
		v.clear();
		ans = neg = s = c = 0;
		cin >> n;
		while(n--) {
			cin >> tmp;
			if (tmp < 0) v.push_back(tmp);
			else {
				s += tmp;
				c++;
			}
		}
		sort(v.rbegin(), v.rend());
		for (int i = 0; i < v.size(); i++) {
			if (((s + v[i]) * (c + 1)) - (s * c) > v[i]) {
				s += v[i];
				c++;
			}
			else {
				neg += v[i];
			}
		}
		cout << neg + (s * c) << "\n";
	}
	return 0;
} 