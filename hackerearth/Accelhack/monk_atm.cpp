#include<bits/stdc++.h>
using namespace std;

vector<int> f;

int factors_count(int x) {
	int ans = 1;
	for (int i = 1; i < f.size() && f[i] <= x; i++) {
		if (x % f[i] == 0) {
			ans++;
		}
	}
	return ans;
}

vector<int> factors_of(int x) {
	vector<int> ans;
	stack<int> others;
	for (int i = 1; i <= sqrt(x); i++) {
		if (x % i == 0) {
			ans.push_back(i);
			others.push(x / i);
		}
	}
	while(others.size()) {
		if (others.top() != ans.back()) ans.push_back(others.top());
		others.pop();
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n, fc, ans;
    
    cin >> t;
    while(t--) {
    	cin >> n;
    	ans = 0;
    	f = factors_of(n);
    	for (int i = 0; i < f.size(); i++) {
    		fc = factors_count(f[i]);
    		if (pow(2, (int)log2(fc)) == fc) ans = max(ans, fc);
    	}
    	cout << ans << "\n";
    }

	return 0;
}