#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, k, occ;
    char prev;
    string in;
    vector<int> freq;

    cin >> t;
    while(t--) {
        cin >> n >> k;
        freq.clear();
        cin >> in;
        prev = in[0];
        occ = 1;
        for (int i = 1; i < in.length(); i++) {
            if (in[i] != prev) {
                freq.push_back(occ);
                occ = 1;
                prev = in[i];
            }
            else {
                occ++;
            }
        }
        freq.push_back(occ);
        ///////////////////////////////////

        /*for (int i = 0; i < freq.size(); i++) {
            cout << freq[i] << " ";
        }
        cout << endl;*/
    }

    return 0;
}
