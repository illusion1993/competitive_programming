#include<bits/stdc++.h>
using namespace std;

int t, n, m, a[300000], b[200];

int findScoreInThisChance(int chance_no, int score_so_far, int from, int to) {
    bool isChef = !(chance_no % 2);
    vector<int> possible_scores;

    int score_at_this_pos, optimal_score, result_score;
    bool optimal_found = false;

    for (int i = from; i <= to + 1 - b[chance_no]; i++) {
        int score_at_this_pos = score_so_far;

        for (int j = i; j < i + b[chance_no]; j++) {
            score_at_this_pos = (isChef) ? score_at_this_pos + a[j] : score_at_this_pos - a[j];
        }

        result_score = (chance_no != m - 1) ? findScoreInThisChance(chance_no + 1, score_at_this_pos, i + 1, i + b[chance_no] - 2) : score_at_this_pos;
        possible_scores.push_back(result_score);

        if (!optimal_found) {
            optimal_found = true;
            optimal_score = result_score;
        }
        else {
            optimal_score = (isChef) ? max(optimal_score, result_score) : min(optimal_score, result_score);
        }
    }

    return optimal_score;
}

int main() {
    cin >> t;

    while(t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        cout << findScoreInThisChance(0, 0, 0, n - 1) << endl;
    }

    return 0;
}
