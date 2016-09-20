#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    // sieve implementation
    vector<int> isPrime(n + 1, 1);
    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    // printing out primes
    for (int i = 0; i < isPrime.size(); i++) {
        if (isPrime[i]) cout << i << endl;
    }
    return 0;
}
