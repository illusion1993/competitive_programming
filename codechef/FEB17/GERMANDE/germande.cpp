#include<bits/stdc++.h>
using namespace std;

int main() {

    int t, total_states, districts_in_state, a[1000000], ones[1000000], ones_governors;
    cin >> t;

    while(t--) {
        ones_governors = 0;
        memset(ones, 0, sizeof(ones));
        cin >> total_states >> districts_in_state;
        for (int i = 0; i < total_states * districts_in_state; i++) {
            cin >> a[i];

            if (a[i]) {
                ones[i / districts_in_state]++;
                cout << "Ones in state " << i / districts_in_state << " increased to " << ones[i / districts_in_state] << endl;
                if (ones[i / districts_in_state] == (districts_in_state / 2) + 1) {
                    ones_governors++;
                    cout << "This caused one more governor from ones side" << endl;
                }
            }
        }

        int pos = 0;
        while(ones_governors <= total_states / 2 && pos < districts_in_state - 1) {

            cout << "Window pos is: " << pos << endl;
            for (int i = 0; i < total_states; i++) {
                cout << "shifting the state " << i + 1 << ", ";
                int new_ones = ones[i] + a[((i * districts_in_state) + pos + districts_in_state) % districts_in_state] - a[i * districts_in_state + pos];
                cout << "now ones are: " << new_ones << endl;

                if (new_ones == (districts_in_state / 2) + 1 && new_ones > ones[i]) {
                    ones_governors++;
                    cout << "This caused one more governor from ones side" << endl;
                }
                else if (new_ones == districts_in_state / 2 && new_ones < ones[i]) {
                    ones_governors--;
                    cout << "This caused one less governor from ones side" << endl;
                }
            }

            pos++;
        }

        if (ones_governors > total_states / 2) cout << "1" << endl;
        else cout << "0" << endl;

    }

    return 0;
}
