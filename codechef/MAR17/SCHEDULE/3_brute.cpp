#include <bits/stdc++.h>
using namespace std;

int t, n, k, occ, tmp;
vector<int> freq;
string sch;

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


int get_min_block(vector<int> inversions_made, int inversions_left) {
    int min_block_size = INT_MAX;

    if (!inversions_left) {
        min_block_size = 0;
        for (int i = 0; i < freq.size(); i++) {
            min_block_size = max(max_size_on_inversions(freq[i], inversions_made[i]), min_block_size);
        }
    }

    else {
        vector<int> new_inversions;
        for (int i = 0; i < freq.size(); i++) {
            int pos = (i == 0) ? (freq.size() == 1) ? 2 : 1 : (i == freq.size() - 1) ? 1 : 0;
            if (inversions_made[i] < inversion_limit(freq[i], pos)) {
                new_inversions = inversions_made;
                new_inversions[i]++;
                min_block_size = min(min_block_size, get_min_block(new_inversions, inversions_left - 1));
            }
        }
        min_block_size = min(min_block_size, get_min_block(inversions_made, 0));
    }

    return min_block_size;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while(t--) {
        freq.clear();
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

        vector<int> inversions_made;
        for (int i = 0; i < n; i++) inversions_made.push_back(0);

        cout << get_min_block(inversions_made, k) << endl;

    }

    return 0;
}
