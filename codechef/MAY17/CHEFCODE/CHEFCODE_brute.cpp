#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll k, prod, c;
vector<ll> v;

void find(int pos) {
	if (pos == v.size()) return;
	if (k / prod >= v[pos]) {
		prod *= v[pos];
		c++;
		find(pos + 1);
		prod /= v[pos];
	}
	find(pos + 1);
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
    c = 0;
    prod = 1;
    find(0);
    cout << c;

}

/*
10 10000000000
2 3 3 4 3 2 3 4 3 2

20 1000000000000000000
2 3 3 4 3 2 3 4 3 2 2 3 3 4 3 2 3 4 3 2

30 1000000000000000000
2 3 3 4 3 2 3 4 3 2 2 3 3 4 3 2 3 4 3 2 2 3 3 4 3 2 3 4 3 2

*/