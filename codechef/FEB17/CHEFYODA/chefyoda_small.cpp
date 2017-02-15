#include<bits/stdc++.h>
using namespace std;

int fact(int n) {
    if (n == 1 || n == 0) return 1;
    return n * fact(n - 1);
}

long long ncr(long long n, long long r) {

    if (n == r || r == 0) return 1;
    return (fact(n) / fact(r)) / fact(n - r);

}

int main() {

    int t, n, m, tmp;
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
                tmp = ncr(k, i);
                prob += tmp;
            }
            for (int i = 0; i < k; i++) prob /= 2;
        }
        cout << fixed << std::setprecision(6) << prob << endl;
    }

    return 0;
}
