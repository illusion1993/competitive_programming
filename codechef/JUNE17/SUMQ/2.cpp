#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

map<ll, pair<bool, bool> > v;
vector<ll> b;

ll count_f() {
	
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    // ifstream cin("tc.txt");
    // ofstream cout("1_out.txt");
    
    int t, p, q, r;
    ll tmp;
    cin >> t;

    while(t--) {
    	cin >> p >> q >> r;

    	v.clear();
    	b.clear();
    	b.resize(q);
    	
    	for (int i = 0; i < p; i++) { cin >> tmp; v[tmp] = {1, 0}; }
		for (int i = 0; i < q; i++) { cin >> b[i]; }
		for (int i = 0; i < r; i++) {
			cin >> tmp;
			if (!v.count(tmp)) v[tmp] = {0, 1};
    		else v[tmp].second = 1;
		}

		sort(b.begin(), b.end());
		// cout << count_f() << "\n";
		cout << "0\n";
    }

    return 0;
}

/*

2
8 5 7
5 6 8 9 11 14 15 20
5 9 10 17 20
5 7 8 9 10 14 19
2 1 2
6 8
9
7 8

*/