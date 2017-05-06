#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;    
ll k, tmp;
vector<ll> v;

void merge(const vector<ll> &c) {
	int pv = 0, pc = 0;
	vector<ll> ans;

	while(pv != v.size() || pc != c.size()) {
		if (pv < v.size() && pc < c.size()) {
			if (v[pv] <= c[pc]) { ans.push_back(v[pv]); pv++; }
			else { ans.push_back(c[pc]); pc++; }
		}
		else {
			if (pv < v.size()) while(pv != v.size()) { ans.push_back(v[pv]); pv++; }
			else while(pc != c.size()) { ans.push_back(c[pc]); pc++; }
		}
	}
	v = ans;
}

void checkFor(int a) {
	vector<ll> mySubSeq;
	mySubSeq.push_back(a);
	for (int i = 0; i < v.size() && k / v[i] >= a; i++) mySubSeq.push_back(v[i] * a);
	merge(mySubSeq);
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;
    while(n--) {
    	cin >> tmp;
    	if (tmp <= k) {
    		checkFor(tmp);
    	}
    }
    cout << v.size();

}