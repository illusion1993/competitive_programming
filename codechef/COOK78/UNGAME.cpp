#include <bits/stdc++.h>

using namespace std;

int inverse_player (int player) {
    return (player == 1) ? 2 : 1;
}

int play (int n, int x, int k, int p) {

    if (x < 1 || x > n) return p;

    if (x - k < 1 && x + k > n) {
        return inverse_player(p);
    }

    return (play(n, x - k, k + 1, inverse_player(p)) == p || play(n, x + k, k + 1, inverse_player(p)) == p) ? p : inverse_player(p);

}

int main () {

    int t, n, m, x;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> x;
            cout << play(n, x, 1, 1) << " ";
        }
        cout << "\n";
    }

    return 0;
}
