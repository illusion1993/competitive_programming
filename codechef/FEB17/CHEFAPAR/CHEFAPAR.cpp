#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n, in, fine, unpaid;

    cin >> t;
    while(t--) {
        fine = 0;
        unpaid = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> in;

            if (!in) {
                fine++;
                unpaid++;
            }

            else {
                if (unpaid) fine++;
            }
        }
        cout << (fine * 100) + (unpaid * 1000) << endl;
    }
    return 0;
}
