#include <bits/stdc++.h>
using namespace std;

int t, n, k, occ, tmp, min_block_size;
vector<int> freq;
string sch;

int max_occ(string s) {
    int occ = INT_MIN, this_occ;
    this_occ = 1;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) this_occ++;
        else {
            occ = max(occ, this_occ);
            this_occ = 1;
        }
    }
    occ = max(occ, this_occ);
    return occ;
}

void get_min_block(string sch, int pos, int inversions_so_far) {
    if (pos == sch.length()) {
        min_block_size = min(min_block_size, max_occ(sch));
    }
    else {
        get_min_block(sch, pos + 1, inversions_so_far);
        if (inversions_so_far < k) {
            sch[pos] = (sch[pos] == '0') ? '1' : '0';
            get_min_block(sch, pos + 1, inversions_so_far + 1);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while(t--) {
        freq.clear();
        cin >> n >> k >> sch;
        min_block_size = INT_MAX;
        get_min_block(sch, 0, 0);
        cout << min_block_size << endl;
    }

    return 0;
}
