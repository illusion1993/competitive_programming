#include<bits/stdc++.h>
using namespace std;

int t, n, m, b[201];
long long sums[300001], in, score;

void play(int chance_no, int pos, long long score_so_far) {
    int interval_size = b[chance_no];
    if (chance_no % 2) score_so_far -= sums[pos + interval_size - 1] - sums[pos - 1];
    else score_so_far += sums[pos + interval_size - 1] - sums[pos - 1];

    if (chance_no != m - 1) {
        for (int i = 1; i < interval_size - b[chance_no + 1]; i++) {
            play(chance_no + 1, pos + 1, score_so_far);
        }
    }
    else score = max(score, score_so_far);
}

int main() {

    cin >> t >> n >> m;
    while(t--) {
        score = 0;
        sums[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> in;
            sums[i] = sums[i - 1] + in;
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        for (int pos = 1; pos <= n - b[0] + 1; pos++) play(0, pos, 0);
        cout << score << endl;
    }

    return 0;
}
