#include<bits/stdc++.h>
using namespace std;

int main() {

    int t, total_states, districts_in_state, a[1000000], ones[1000000], ones_governors, shift;
    cin >> t;

    while(t--) {
        memset(ones, 0, sizeof(ones));
        cin >> total_states >> districts_in_state;

        for (int i = 0; i < total_states * districts_in_state; i++) {
            cin >> a[i];
            if (i < districts_in_state) ones[0] += a[i];
        }
        // count ones for all positions of state begin border
        for (int i = 1; i < total_states * districts_in_state; i++) {
            ones[i] = ones[i - 1];
            ones[i] -= a[i - 1];
            ones[i] += a[(i + districts_in_state - 1) % (districts_in_state * total_states)];
        }

        shift = 0;
        ones_governors = 0;
        while(ones_governors < (total_states / 2) + 1 && shift < districts_in_state) {
            ones_governors = 0;
            for (int i = 0; i < total_states; i++) {
                if (ones[(i * districts_in_state) + shift] > districts_in_state / 2) {
                    ones_governors++;
                }
            }
            shift++;
        }
        if (ones_governors > total_states / 2) cout << "1" << endl;
        else cout << "0" << endl;

    }

    return 0;
}
