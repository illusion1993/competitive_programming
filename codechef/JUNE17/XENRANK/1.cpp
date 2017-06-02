#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll get_rank(ll x, ll y) {
	ll l, p;
	l = x + y;
	p = (l * (l + 1)) / 2;
	return p + x + 1;
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    ll x, y;
    cin >> t;
    while(t--) {
    	cin >> x >> y;
    	cout << get_rank(x, y) << "\n";
    }

    return 0;
}
