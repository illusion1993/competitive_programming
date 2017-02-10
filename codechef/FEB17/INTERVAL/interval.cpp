#include<bits/stdc++.h>
using namespace std;

int t, n, m, b[201];
long long sums[300001], in;

map<pair<int, int>, long long> delta;

long long get_score(int chance_no, int from, int to) {
    if (chance_no == m) return 0;

    long long score_in_this_chance, tmp_score;
    score_in_this_chance = delta[make_pair(b[chance_no], from + b[chance_no] - 1)];
    score_in_this_chance -= get_score(chance_no + 1, from + 1, from + b[chance_no] - 2);

    for (int i = from + b[chance_no]; i <= to; i++) {
        tmp_score = delta[make_pair(b[chance_no], i)];
        tmp_score -= get_score(chance_no + 1, i - b[chance_no] + 2, i - 1);
        score_in_this_chance = max(score_in_this_chance, tmp_score);
    }
    return score_in_this_chance;
}

int main() {

    cin >> t >> n >> m;
    while(t--) {
        delta.clear();
        sums[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> in;
            sums[i] = sums[i - 1] + in;
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
            for (int delta_pos = b[i] + i; delta_pos <= n - i; delta_pos++) {
                delta[make_pair(b[i], delta_pos)] = sums[b[i]] - sums[delta_pos - b[i]];
            }
        }

        cout << get_score(0, 1, n) << endl;
    }

    return 0;
}
