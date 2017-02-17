#include<bits/stdc++.h>
using namespace std;

map<pair<int, int>, long long> ncrs;

long long ncr(long long n, long long r) {
    if (n == r || r == 0) return 1;
    if (r == 1) return n;


    long long a, b;
    a = (ncrs.count({n - 1, r})) ? ncrs[{n - 1, r}] : ncr(n - 1, r);
    b = (ncrs.count({n - 1, r - 1})) ? ncrs[{n - 1, r - 1}] : ncr(n - 1, r - 1);

    ncrs[{n, r}] = a + b;
    ncrs[{n, n - r}] = a + b;

    return a + b;
}

int main() {

    int t, n, m;
    float prob, p, k;

    cin >> t;
    while(t--) {
        prob = 0;
        cin >> n >> m >> p >> k;

        if ((n % 2 == 0 && m % 2 == 0) || p == 0) {
            prob = 1.0;
        }
        else if (n % 2 == 1 && m % 2 == 1) {
            prob = 0.0;
        }
        else {
            for (int i = p; i <= k; i++) {
                prob += ncr(k, i);
            }
            for (int i = 0; i < k; i++) prob /= 2;
        }
        cout << fixed << std::setprecision(6) << prob << endl;
    }

    return 0;
}
