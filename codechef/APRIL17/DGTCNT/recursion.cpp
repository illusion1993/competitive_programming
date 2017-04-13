#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> lv, rv;
vector<int> a(10);

ll countSad(int pos, int low, int high, vector<int> remaining_a) {
	ll p = 0;
	if (pos == lv.size()) {
		
	}
	return p;
}

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    ll l, r;

    cin >> t;
    while(t--) {
    	cin >> l >> r;
    	for (int i = 0; i < 10; i++) cin >> a[i];
		stack<int> s;
    	while(l) {
    		s.push(l % 10);
    		l /= 10;
    	}
    	while(!s.empty()) {
    		lv.push_back(s.top());
    		s.pop();
    	}
    	while(r) {
    		s.push(r % 10);
    		r /= 10;
    	}
    	while(!s.empty()) {
    		rv.push_back(s.top());
    		s.pop();
    	}
    	int pos = 0;
    	while(lv[pos] == rv[pos] && pos < lv.size()) {
    		a[lv[pos]]--;
    		pos++;
    	}
    	if (pos == lv.size()) {
    		cout << "0\n";
    	}
    	else {
    		cout << r - l + 1 - countSad(pos, lv[pos], rv[pos], a) << "\n";
    	}
    }

	return 0;
}