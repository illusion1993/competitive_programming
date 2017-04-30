#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

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

ll ncrMod(ll n)
{
    ll b = invMod(2, M);
    ll a = ((n % M) * ((n - 1) % M)) % M;

    return (a * b) % M;
}

ll sumApMod(ll a, ll l, ll m) {
	if (a == l) return a % m;
	ll sum, n = l - a + 1;
    sum = ((a % m) * (n % m)) % m;
    sum = (sum + ncrMod(n)) % m;

	return sum;
}

ll sumDiv(ll n, ll m) {
	if (n == 2) return 5;
	else if (n == 3) return 11;

	ll prev = n, sum = 0;
	int sq = sqrt(n);

	sum = (sum + ((ncrMod(n) + n) % m)) % m;	// adding all occurences of 1
	for (int i = 2; i <= sq; i++) {
		ll a = n / i;
		sum = (sum + (((ncrMod(a) + a) * i) % m)) % m;	// adding all occurences of i
		sum = (sum + (((ncrMod(i - 1) + i - 1) % m) * sumApMod(a + 1, prev, m)) % m) % m;
		if (i == sq && a != i) {
			sum = (sum + (((ncrMod(i) + i) % m) * sumApMod(i + 1, a, m)) % m) % m; // adding all occurences of i + 1 to a
		}
		prev = a;
	}
	return sum;
}

int main()
{
    long long n;
    cin >> n;
    cout << sumDiv(n, 1000000007);
    return 0;
}
