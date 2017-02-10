#include<bits/stdc++.h>
using namespace std;

int main() {

    int t, total_states, districts_in_state, a[1000000], ones[1000000], ones_governors, shift;
    cin >> t;

    while(t--) {
        bool found = false;
        ones_governors = 0;
        memset(ones, 0, sizeof(ones));
        cin >> total_states >> districts_in_state;

        // count number of 1's in each state
        for (int i = 0; i < total_states * districts_in_state; i++) {
            cin >> a[i];
            if (a[i]) {
                ones[i / districts_in_state]++;
                // if ones in this state are many, it means the governor is one
                if (ones[i / districts_in_state] == (districts_in_state / 2) + 1) ones_governors++;
            }
        }

        if (ones_governors > total_states / 2) {
            cout << "1" << endl;
            found = true;
        }
        else{
            for (shift = 1; shift <= districts_in_state; shift++) {
            // try making all possible shifts
                for (int i = 0; i < total_states; i++) {
                // compute ones etc for all states in new shift
                    int state_begin_new_index = (i * districts_in_state) + shift;
                    int ones_now = ones[i] - a[state_begin_new_index - 1] + a[(state_begin_new_index + districts_in_state - 1) % (total_states * districts_in_state)];

                    if (ones_now > ones[i] && ones_now == (districts_in_state / 2) + 1) ones_governors++;
                    else if (ones_now < ones[i] && ones_now == (districts_in_state / 2)) ones_governors--;
                }

                // if in this new shift, ones governors are more, cout 1 and break loop
                if (ones_governors == (total_states / 2) + 1) {
                    cout << "1" << endl;
                    found = true;
                    break;
                }
            }
        }

        if (!found) cout << "0" << endl;

    }

    return 0;
}
