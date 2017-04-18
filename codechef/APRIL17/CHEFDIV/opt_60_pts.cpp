#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> primes;     // This stores prime numbers till sqrt(B) B is the last number in input range
map<int, int> prime_factors;    // Power : factors_count
ll total_factors;

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

void factorize(ll x) {
    prime_factors.clear();
    total_factors = 1;
    int power;
    for (int i = 0; i < primes.size() && x > 1; i++) {
        power = 0;
        while (x % primes[i] == 0) {
            power++;
            x /= primes[i];
        }
        if (power) {
            prime_factors[power] = (prime_factors.count(power)) ? prime_factors[power] + 1 : 1;
            total_factors *= (power + 1);
        }
    }
    if (x != 1) {
        power = 1;
        prime_factors[power] = (prime_factors.count(power)) ? prime_factors[power] + 1 : 1;
        total_factors *= (power + 1);
    }
}

void reduceFactor() {
    int max_power = prime_factors.rbegin() -> first;
    total_factors /= (max_power + 1);
    total_factors *= (max_power);
    if (prime_factors[max_power] == 1) prime_factors.erase(max_power);
    else prime_factors[max_power]--;
    if (max_power > 1)
        prime_factors[max_power - 1] = (prime_factors.count(max_power - 1)) ? prime_factors[max_power - 1] + 1 : 1;
}

ll findScore(ll x) {
    factorize(x);
    ll score = 0;

    while(total_factors > 1) {
        score += total_factors;
        reduceFactor();
    }

    return score;
}


int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll l, r, ans = 0;
    cin >> l >> r;
    findPrimes(r);  // pass largest input
    for (ll i = l; i <= r; i++) {
        ans += findScore(i);
    }
    cout << ans;

    return 0;
}
