#include <bits/stdc++.h>
using namespace std;

int inversion_limit(int block_size, int pos) {
    int in_lim = ceil(((float)block_size - 2.00) / 2.00);
    if (pos == 2) in_lim++;
    else if (pos == 1 && block_size % 2 == 0) in_lim++;
    return in_lim;
}

int max_size_on_inversions(int block_size, int inversions) {
    if ((block_size % 2 && inversions > block_size / 2) || (block_size % 2 == 0 && inversions == block_size / 2)) {
        return 1;
    }
    return ceil((float)(block_size - inversions) / (float)(inversions + 1));
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n, k, occ, tmp;
    vector<int> freq, dp0, dp1;
    string sch;

    cin >> t;
    while(t--) {
        freq.clear();
        dp0.clear();
        dp1.clear();
        cin >> n >> k >> sch;
        occ = 1;
        for (int i = 1; i < n; i++) {
            if (sch[i] == sch[i - 1]) occ++;
            else {
                freq.push_back(occ);
                occ = 1;
            }
        }
        freq.push_back(occ);

        tmp = inversion_limit(freq[0], (freq.size() > 1) ? 1 : 2);
        for (int i = 0; i <= k; i++) {
            if (i <= tmp) {
                dp0.push_back(max_size_on_inversions(freq[0], i));
                dp1.push_back(max_size_on_inversions(freq[0], i));
            }
            else {
                dp0.push_back(dp0[dp0.size() - 1]);
                dp1.push_back(dp0[dp0.size() - 1]);
            }
        }

        for (int i = 1; i < freq.size(); i++) {
            tmp = inversion_limit(freq[i], i == freq.size() - 1);
            dp1.clear();
            for (int l = 0; l <= k; l++) {
                int j = 0, min_poss = INT_MAX;
                while(l - j >= 0 && j <= tmp) {
                    min_poss = min(min_poss, max(dp0[l - j], max_size_on_inversions(freq[i], j)));
                    j++;
                }
                dp1.push_back(min_poss);
            }
            dp0 = dp1;
        }
        cout << dp1.back() << endl;

    }

    return 0;
}
