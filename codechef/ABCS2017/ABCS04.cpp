#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t, m, n;
    cin >> t;
    while(t--) {
        cin >> m >> n;
        if (m == n) cout << "SAMBAR\n";
        else if (m > n) cout << "IDLY\n";
        else cout << "VADA";
    }
    return 0;
}
