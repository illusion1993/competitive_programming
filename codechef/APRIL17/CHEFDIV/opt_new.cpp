#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> primes;
void findPrimes(ll x) {
    int n = sqrt(x) + 1;
    bool sieve[n];
    memset(sieve, 0, sizeof(sieve));

    for (int i = 3; i < n; i += 2) {
        if (!sieve[i]) {
            for (int j = 3; i*j < n; j += 2) {
                sieve[i*j] = 1;
            }
        }
    }

    primes.push_back(2);
    for (int i = 3; i < n; i += 2) if (!sieve[i]) primes.push_back(i);
}

class num {
public:

    void init(ll x) { self_value = x; }

    bool divisibleBy(int x) { return self_value % x == 0; }

    void divideBy(int x) {
        if (self_value % x == 0) {
            self_value /= (ll)x;
            factors.push_back(x);
        }
    }

    ll findScore() {
        if (self_value > 1) factors.push_back(self_value);
        makeFactorMap();
        ll score = 0;

        while(total_factors > 1) {
            score += total_factors;
            reduceFactor();
        }

        return score;
    }

private:
    ll self_value, total_factors;
    vector<int> factors;
    map<int, int> prime_factors_counts;

    void makeFactorMap() {
        total_factors = 1;
        int c = 1;
        for (int i = 1; i < factors.size(); i++) {
            if (factors[i] == factors[i - 1]) c++;
            else {
                prime_factors_counts[c] = (prime_factors_counts.count(c)) ? prime_factors_counts[c] + 1 : 1;
                total_factors *= (c + 1);
                c = 1;
            }
        }
        prime_factors_counts[c] = (prime_factors_counts.count(c)) ? prime_factors_counts[c] + 1 : 1;
        total_factors *= (c + 1);
    }

    void reduceFactor() {
        int max_power = prime_factors_counts.rbegin() -> first;
        total_factors /= (max_power + 1);
        total_factors *= (max_power);
        if (prime_factors_counts[max_power] == 1) prime_factors_counts.erase(max_power);
        else prime_factors_counts[max_power]--;
        if (max_power > 1)
            prime_factors_counts[max_power - 1] = (prime_factors_counts.count(max_power - 1)) ? prime_factors_counts[max_power - 1] + 1 : 1;
    }
};


int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll l, r, ans = 0;
    cin >> l >> r;
    findPrimes(r);
    num range[r - l + 1];
    for (int i = 0; i < r - l + 1; i++) range[i].init(i + l);
    for (int i = 0; i < primes.size(); i++) {
        int p = primes[i];
        int n = (l % p) ? l + (p - (l % p)) : l;
        while(n <= r) {
            while(range[n - l].divisibleBy(p)) range[n - l].divideBy(p);
            n += p;
        }
    }
    for (int i = 0; i < r - l + 1; i++) {
        ans += range[i].findScore();
    }
    cout << ans;

    return 0;
}
