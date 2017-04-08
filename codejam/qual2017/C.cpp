#include<bits/stdc++.h>
using namespace std;
#define ll long long

pair<ll, ll> solve(ll n, ll k) {
	int level = floor(log2(k)), div = 0;
	ll upper_nodes = pow(2, level) - 1, low, high, highcount = 1, nodes;
	low = high = n;
	nodes = upper_nodes + 1;
	while(div != level) {
		low = floor(((double)low - 1.0) / 2.0);
		high = ceil(((double)high - 1.0) / 2.0);
		div++;
	}
	highcount = (low == high) ? nodes : (n - upper_nodes - (low * nodes)) / (high - low);
	double val = ((k - upper_nodes) <= highcount) ? double(high - 1) / 2.0 : double(low - 1) / 2.0;
	pair<ll, ll> ans;
	ans.first = ceil(val);
	ans.second = floor(val);
	return ans;
}

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
    cin.tie(0);

    ofstream cout ("C-large.out");
    ifstream cin ("C-large.in");

    int t;
    ll in, in1;
    cin >> t;
    pair<ll, ll> ans;
    for (int tc = 1; tc <= t; tc++) {
    	cin >> in >> in1;
    	ans = solve(in, in1);
    	cout << "Case #" << tc << ": " << ans.first << " " << ans.second << "\n";
    }

	return 0;
}