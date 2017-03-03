#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, in, s1, s2;
    cin >> t;
    while(t--) {
        cin >> n;
        s1 = 0;
        s2 = 0;
        for (int i = 0; i < n; i++) {
            cin >> in;
            if (i % 2) s2 += in;
            else s1 += in;
        }
        for (int i = 0; i < n; i++) {
            cin >> in;
            if (i % 2) s1 += in;
            else s2 += in;
        }
        cout << min(s1, s2) << "\n";
    }

    return 0;
}
