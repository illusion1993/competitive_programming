#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;    
    ll k, tmp;
    vector<ll> v;
    
    cin >> n >> k;
    while(n--) {
    	cin >> tmp;
    	if (tmp <= k) {
    		int s = v.size();
    		for (int i = 0; i < s; i++) {
	    		if (k / v[i] >= tmp) v.push_back(v[i] * tmp);
	    	}
	    	v.push_back(tmp);
    	}
    }
    cout << v.size();

}