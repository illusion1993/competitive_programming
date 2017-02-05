#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n, a[100000], z_count, seconds;
    bool isSorted;

    cin >> t;

    while(t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        isSorted = false;
        seconds = 0;
        while(!isSorted) {
            z_count = 0;
            for (int i = 0; i < n - 1; i++) {
                if (!a[i] && a[i + 1]) {
                    z_count++;
                    a[i] = !a[i];
                    a[i + 1] = !a[i + 1];
                    i++;
                }
            }

            if (z_count) seconds++;
            else isSorted = true;
        }
        cout << seconds << endl;
    }
    return 0;
}
