#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, filled, fill_in;
    bool in;

    cin >> t;
    while(t--) {
        cin >> n;
        filled = 0;
        fill_in = n - 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> in;
                if (fill_in >= 0 && filled == (n - 1 - fill_in) * 2) {
                    fill_in--;
                    filled = 0;
                }
                if (!in && fill_in >= 0) filled++;
            }
        }
        if (fill_in >= 0) {
            if (filled == (n - 1 - fill_in) * 2) cout << fill_in << "\n";
            else cout << fill_in + 1 << "\n";
        }
        else cout << "0\n";
    }

    return 0;
}
