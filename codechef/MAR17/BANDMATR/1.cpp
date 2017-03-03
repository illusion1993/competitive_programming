#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, filled[500], fill_in;
    bool in;

    cin >> t;
    while(t--) {
        memset(filled, 0, sizeof(filled));
        cin >> n;
        fill_in = n - 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> in;
                if (fill_in >= 0 && filled[fill_in] == (n - 1 - fill_in) * 2) fill_in--;
                if (!in && fill_in >= 0) filled[fill_in]++;
            }
        }
        if (fill_in >= 0) {
            if (filled[fill_in] == (n - 1 - fill_in) * 2) {
                cout << fill_in << "\n";
            }
            else {
                cout << fill_in + 1 << "\n";
            }
        }
        else cout << "0\n";
    }

    return 0;
}
