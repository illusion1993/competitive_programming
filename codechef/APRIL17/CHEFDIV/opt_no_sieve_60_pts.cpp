#include<bits/stdc++.h>
using namespace std;
#define ll long long

map<int, int> prime_factors;
ll total_factors;

void factorize(ll x) {
    prime_factors.clear();
    total_factors = 1;
    int power;
    power = 0;
    
    while (x % 2 == 0) {
        power++;
        x /= 2;
    }
    if (power) {
        prime_factors[power] = 1;
        total_factors *= (power + 1);
    }
    
    for (int i = 3; i <= sqrt(x) && x > 1; i += 2) {
        power = 0;
        while (x % i == 0) {
            power++;
            x /= i;
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
    for (ll i = l; i <= r; i++) {
        ans += findScore(i);
    }
    cout << ans;

    return 0;
}
