#include <bits/stdc++.h>
using namespace std;

int t, n, k, min_block_size;
vector<int> freq;

void compare_min_block_size(vector<int> inversions_made) {
    cout << "Checking for inversions made: ";
    for (int i = 0; i < inversions_made.size(); i++) cout << inversions_made[i] << " ";
    cout << "\n";


    int max_block_in_this = INT_MIN, i;
    for (i = 0; i < inversions_made.size(); i++) {
        max_block_in_this = max(max_block_in_this, (int)ceil(((float)freq[i] - (float)inversions_made[i]) / ((float)inversions_made[i] + 1.00)));
    }
    while(i < freq.size()) {
        max_block_in_this = max(freq[i], max_block_in_this);
        i++;
    }
    cout << "Largest block size is: " << max_block_in_this << endl;
    min_block_size = min(min_block_size, max_block_in_this);
}

void invert(vector<int> inversions_made, int pos, int k_left, bool left_invert) {
    if (pos == freq.size() || !k_left) {
        compare_min_block_size(inversions_made);
    }
    else {
        if (!left_invert) {
            for (int i = 0; i < (freq[pos] + (freq[pos] % 2)) / 2; i++) {
                if (k_left - i >= 0) {
                    inversions_made.push_back(i);
                    invert(inversions_made, pos + 1, k_left - i, false);
                    inversions_made.pop_back();
                }
            }

            // right inversion
            if (k_left >= (freq[pos] + (freq[pos] % 2)) / 2) {
                cout << "Doing right inversion on " << freq[pos] << endl;
                inversions_made.push_back((freq[pos] + (freq[pos] % 2)) / 2);
                invert(inversions_made, pos + 1, k_left - (freq[pos] + (freq[pos] % 2)) / 2, true);
                inversions_made.pop_back();
            }
        }
        // left inversion
        if ((left_invert || pos == 0) && k_left >= (freq[pos] + (freq[pos] % 2)) / 2) {
            cout << "Doing left inversion on " << freq[pos] << endl;
            inversions_made.push_back(-1 * (freq[pos] + (freq[pos] % 2)) / 2);
            invert(inversions_made, pos + 1, k_left - (freq[pos] + (freq[pos] % 2)) / 2, false);
            inversions_made.pop_back();
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int occ;
    string sch;

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
        min_block_size = INT_MAX;
        invert(inversions_made, 0, k, false);
        cout << min_block_size << "\n";
    }

    return 0;
}
