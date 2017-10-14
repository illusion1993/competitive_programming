#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
int units[4] = { 2, 3, 5, 7 };

void make_primes(int n) {
    int nn = n * 10;
    for (int i = 0; i < 4; i++) {
        if (nn + units[i] < 100000) {
            primes.push_back(nn + units[i]);
            make_primes(nn + units[i]);
        }
    }
    sort(primes.begin(), primes.end());
}

int main()
{    
    make_primes(0);
    
    int n, pos = 0;
    cin >> n;
    while (primes[pos] <= n && pos < primes.size()) {
        pos++;
    }
    cout << primes[pos - 1];
    return 0;
}
