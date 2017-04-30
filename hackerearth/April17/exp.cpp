#include<bits/stdc++.h>
using namespace std;
#define ll long long
// #define fl float

ll invMod(ll k, ll m)
{
    if (m == 0) return (k == 1 || k == -1) ? k : 0;
    if (m < 0) m = -m;
    k %= m;
    if (k < 0) k += m;
    int neg = 1;
    ll p1 = 1, p2 = 0, k1 = k, m1 = m, q, r, temp;
    while(k1 > 0) {
        q = m1 / k1;
        r = m1 % k1;
        temp = q*p1 + p2;
        p2 = p1;
        p1 = temp;
        m1 = k1;
        k1 = r;
        neg = !neg;
    }
    return neg ? m - p2 : p2;
}

int main()
{
	
    ll b = invMod(2, 7);
    cout << b << endl;
    for (ll a = 10; a <= 100; a+=2) {
        ll p1, p2;
        p1 = (a / 2) % 7;
        p2 = ((a % 7) * b) % 7;
        if (p1 == p2) cout << p1 << " " << p2 << " OKAY\n";
        else {
            cout << p1 << " " << p2 << " ------> ERR\n";
            break;
        }
    }

    return 0;
}
