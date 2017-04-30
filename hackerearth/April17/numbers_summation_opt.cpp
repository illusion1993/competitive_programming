#include<bits/stdc++.h>
using namespace std;
#define ll long long

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

ll factExp(ll n, ll p)
{
    ll ex = 0;
    do
    {
        n /= p;
        ex += n;
    }while(n > 0);
    return ex;
}

// Preconditions: 0 <= k <= min(n,p-1); p > 1 prime
ll ncrMod2(ll n, ll k, ll p)
{
    // reduce n modulo p
    n %= p;
    // Trivial checks
    if (n < k) return 0;
    if (k == 0 || k == n) return 1;
    // Now 0 < k < n, save a bit of work if k > n/2
    if (k > n/2) k = n-k;
    // calculate numerator and denominator modulo p
    ll num = n, den = 1;
    for(n = n-1; k > 1; --n, --k)
    {
        num = (num * n) % p;
        den = (den * k) % p;
    }
    // Invert denominator modulo p
    den = invMod(den,p);
    return (num * den) % p;
}

// Preconditions: 0 <= k <= n; p > 1 prime
ll ncrMod1(ll n, ll k, ll p)
{
    // For small k, no recursion is necessary
    if (k < p) return ncrMod2(n,k,p);
    ll q_n, r_n, q_k, r_k, choose;
    q_n = n / p;
    r_n = n % p;
    q_k = k / p;
    r_k = k % p;
    choose = ncrMod2(r_n, r_k, p);
    // If the exponent of p in choose(n,k) isn't determined to be 0
    // before the calculation gets serious, short-cut here:
    /* if (choose == 0) return 0; */
    choose *= ncrMod1(q_n, q_k, p);
    return choose % p;
}

ll ncrMod(ll n, ll k, ll p)
{
    // We deal with the trivial cases first
    if (k < 0 || n < k) return 0;
    if (k == 0 || k == n) return 1;
    // Now check whether choose(n,k) is divisible by p
    if (factExp(n, p) > factExp(k, p) + factExp(n-k, p)) return 0;
    // If it's not divisible, do the generic work
    return ncrMod1(n,k,p);
}

ll sumApMod(ll a, ll l, ll m) {
	if (a == l) return a % m;
	ll sum, n = l - a + 1;
	// sum = (sum + ((a * (l - a + 1)) % m)) % m;
	// sum = (sum + (((l - a) * (l - a + 1) / 2) % m)) % m;

    sum = ((a % m) * (n % m)) % m;
    sum = (sum + ncrMod(n, 2, m)) % m;

	return sum;
}

ll sumDiv(ll n, ll m) {
	ll sum = 0, t = n / 2;
	sum = sumApMod(t + 1, n, m);

	for (int i = 1; i <= t; i++) {
		ll a = n / i;
		// cout << i << " has " << a << " multiples, \n";
		// cout << i << " comes " << ncrMod(a, 2, m) + a << " times, sum became: ";
		
		sum = (sum + ((((ncrMod(a, 2, m) + a) % m) * i) % m)) % m;
		
		// cout << sum << endl;
	}

	return sum;
}

ll sumDiv2(ll n, ll m) {
	if (n == 2) return 5;
	else if (n == 3) return 11;

	ll prev = n, next, sum = 0;
	int sq = sqrt(n);

	sum = (sum + ((ncrMod(n, 2, m) + n) % m)) % m;	// adding all occurences of 1
	// cout << "For all occurences of 1, sum is: " << ((ncrMod(n, 2, m) + n) % m) << endl;

	for (int i = 2; i <= sq; i++) {
		ll a = n / i;
		sum = (sum + (((ncrMod(a, 2, m) + a) * i) % m)) % m;	// adding all occurences of i
		// cout << "For all occ of " << i << ", sum is: " << ((ncrMod(a, 2, m) + a) % m) << endl;
		
		// cout << "Numbers from " << a + 1 << " to " << prev << " come " << i - 1 << " times:\n";
		// cout << "AP sum is: " << sumApMod(a + 1, prev, m) << "\n";
		sum = (sum + (((ncrMod(i - 1, 2, m) + i - 1) % m) * sumApMod(a + 1, prev, m)) % m) % m;
		// cout << "Sum became: " << sum << endl;
		if (i == sq && a != i) {
			// sum = (sum + (((ncrMod(i, 2, m) + i) * a) % m)) % m;	
			sum = (sum + (((ncrMod(i, 2, m) + i) % m) * sumApMod(i + 1, a, m)) % m) % m; // adding all occurences of i + 1 to a
		}
		prev = a;
		// cout << "For all numbers from " << a + 1 << " to " << " "
	}
	return sum;
}

int main()
{
	srand(time(0));
	long long n, a1, a2;

    // a1 = sumDiv(8, 1000000007);
    // a2 = sumDiv2(8, 1000000007);

    // if (a1 != a2) {
    //     cout << "\n" << n << "\tERR------\n";
    //     cout << a1 << " - " << a2 << "\n";
    // }
    // else {
    //     cout << n << ": ";
    //     cout << a1 << " - " << a2 << "\tOKAY \n";
    // }
    // return 0;

	for (int i = 1; i < 20; i++) {
		for (int j = 0; j < 50; j++) {
			n = 2;
			for (int p = 0; p < i; p++) n *= ((rand() % 10) + 1);
		
			a1 = sumDiv(n, 1000000007);
			a2 = sumDiv2(n, 1000000007);

			if (a1 != a2) {
				cout << "\n" << n << "\tERR------\n";
				cout << a1 << " - " << a2 << "\n";
				break;
			}
			else {
				cout << n << ": ";
				cout << a1 << " - " << a2 << "\tOKAY \n";
			}
		}
	}

    return 0;
}
