#incldue<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define MAXRANGE 40000000000000001

vector<ll> f;
void findEvenFibs() {
	ll a = 1, b = 1, tmp;
	while (b <= MAXRANGE) {
		if (b % 2 == 0) f.push_back(b);
		tmp = b;
		b += a;
		a = tmp;
	}
}

int main(){
    findEvenFibs();
    int t, pos;
    ll s, n;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        s = 0;
        cin >> n;
        pos = 0;
        while(f[pos] <= n) {
            s += f[pos];
            pos++;
        }
        cout << s << endl;
    }
    return 0;
}