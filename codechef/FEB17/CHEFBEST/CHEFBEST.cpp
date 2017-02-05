#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n, in, total_boys, first_boy_pos;

    cin >> t;

    while(t--) {
        total_boys = 0;
        first_boy_pos = -1;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> in;
            if (!in) {
                total_boys++;
                if (first_boy_pos == -1) first_boy_pos = i;
            }
        }
        cout << n - total_boys - first_boy_pos << endl;
    }
    return 0;
}
