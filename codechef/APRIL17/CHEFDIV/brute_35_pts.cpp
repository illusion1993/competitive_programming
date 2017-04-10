#include<bits/stdc++.h>
using namespace std;

#define ll long long

unordered_map<ll, ll> tree_scores;
vector<ll> fac;

vector<ll> factors(ll a) {
    vector<ll> fac;
    stack<ll> s;
    for (ll i = 1; i <= sqrt(a); i++) {
        if (a % i == 0) {
            if (i != a) fac.push_back(i);
            if (i != 1 && i != sqrt(a)) s.push(a / i);
        }
    }
    while(s.size()) {
        fac.push_back(s.top());
        s.pop();
    }
    return fac;
}

ll treeScore(ll root) {
    if (tree_scores.count(root)) return tree_scores[root];
    ll score = 0, child_max_score = 0;
    for (ll i = 0; i < fac.size() && fac[i] < root; i++) {
        if (root % fac[i] == 0) {
            score++;
            child_max_score = max(child_max_score, treeScore(fac[i]) + 1);
        }
    }
    score += child_max_score;
    tree_scores[root] = score;
    return score;
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll l, r, ans = 0;
    cin >> l >> r;
    for (ll i = l; i <= r; i++) {
        fac = factors(i);
        ans += treeScore(i);
    }
    cout << ans;

    return 0;
}
