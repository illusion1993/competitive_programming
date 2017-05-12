#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
ll k;
vector<ll> v;

map<pair<int, ll>, ll> cache;

ll dp(int pos, ll prod) {
    if (pos == 0) return prod >= v[0];
    if (cache.count({pos, prod})) return cache[{pos, prod}];
    ll ans = v[pos] <= prod;
    ans += dp(pos - 1, prod);
    ans += dp(pos - 1, prod / v[pos]);
    cache[{pos, prod}] = ans;
    return ans;
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    ll tmp;
    
    cin >> n >> k;
    while(n--) {
    	cin >> tmp;
    	v.push_back(tmp);
    }
    cout << dp(v.size() - 1, k);

}