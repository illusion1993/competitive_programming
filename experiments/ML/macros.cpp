#include<bits/stdc++.h>
using namespace std;

// Loop
#define LP(x, y) for (typeof(y) x = 0; x < y; ++x)

// Input Output with/without new Line
#define IN(x) cin >> x
#define IN2(x, y) cin >> x >> y
#define IN3(x, y, z) cin >> x >> y >> z

#define OUT(x) cout << x
#define OUT2(x, y) cout << x << " " << y
#define OUT3(x, y, z) cout << x << " " << y << " " << z

#define OUTPREC(n, p) cout << setprecision(p) << n

#define NL cout << "\n"

// Input Testcase number and place while condition
#define INTEST int t; cin >> t; while(t--)

// Array Input Output with/without new line
#define INARR(a, n) for (int i = 0; i < n; i++) cin >> a[i]
#define INARR2(a, b, n) for (int i = 0; i < n; i++) cin >> a[i] >> b[i]
#define INARR3(a, b, c, n) for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i]

#define OUTARR(a, n) for (int i = 0; i < n; i++) cout << a[i] << " "

// Array Input and Sort
#define INARRSORT(a, n) for (int i = 0; i < n; i++) {cin >> a[i];} sort(a, a + n)

// Vectors
#define veci vector<int>

// Even Odd conditions
#define ifeven(x) if (x % 2 == 0)
#define ifodd(x) if (x % 2)

int main() {

	int tmp;
	INTEST{
		IN(tmp);
		OUT(tmp);
	}

	return 0;
}
