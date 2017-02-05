#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n, a[100000], dist_so_far, time, expected_pos;
    cin >> t;

    while(t--) {
        cin >> n;

        dist_so_far = 0;
        time = -1;
        expected_pos = n - 1;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = n - 1; i > -1; i--) {
            //cout << endl << "Bit is " << a[i] << ", distance so far is " << dist_so_far;
            //cout << endl << "Expected pos is " << expected_pos << ", current is " << i;

            if (!a[i] && i != expected_pos) {
                if (time == -1) {
                    time = dist_so_far;
                    //cout << endl << "Time initialized first time to " << time;
                }
                else {
                    time = max(time + 1, time + dist_so_far);
                    //time = (dist_so_far == 1 || dist_so_far == 2) ? time + 1 : time + dist_so_far;
                    //cout << endl << "This is not first 0, time for this is " << time;
                }
                dist_so_far = -1;
                //cout << endl<< "Making distance so far = -1";
            }

            else if (!a[i]) {
                expected_pos--;
                dist_so_far = -1;
                //cout << endl<< "Making distance so far = -1";
            }

            dist_so_far++;
        }
        cout << max(0, time) << endl;
    }
    return 0;
}
