#include<bits/stdc++.h>
using namespace std;

int n, m, l, r, k, freq_size = 0;
long long a[100000];
long long freq[100000][3];  // index, (number, l, r)

int main() {

    cin >> n >> m;

    bool on = false;
    int first_seen;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (i == 0 || (i > 0 && a[i] != a[i - 1])) {
            freq[i][0] = a[i];
            freq[i][1] = i;
            freq[i][2] = i;

            //cout << a[i] << " came, making freq " << a[i] << ", 1 at index " << i << endl;
        }

        if (i != 0 && a[i] == a[i - 1] && !on) {
            on = true;
            first_seen = i - 1;
            //cout << "repetetion at pos " << i << ", first seen at " << first_seen << endl;
        }
        else if (on && a[i] != a[i - 1]) {
            //cout << "at pos " << i << ", " << a[i] << " came, breaking repetition since " << first_seen << " till " << i - 1 << endl;
            on = false;
            for (int j = first_seen; j <= i - 1; j++) {
                freq[j][0] = a[i - 1];
                freq[j][1] = first_seen;
                freq[j][2] = i - 1;
                //cout << a[i] << " came, making freq " << a[i - 1] << ", " << i - first_seen << " at index " << j << endl;
            }
        }
    }
    if (on) {
        for (int j = first_seen; j <= n - 1; j++) {
            freq[j][0] = a[n - 1];
            freq[j][1] = first_seen;
            freq[j][2] = n - 1;
            //cout << "in the end, making freq " << a[n - 1] << ", " << n - first_seen << " at index " << j << endl;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> l >> r >> k;
        l--;
        r--;
        int mid = (l + r) / 2;
        //cout << "mid number is " << a[mid] << ", freq data is " << freq[mid][0] << " - " << freq[mid][1] << " - " << freq[mid][2] << endl;
        if (min(freq[mid][2], (long long)r) - max(freq[mid][1], (long long)l) + 1 >= k) cout << freq[mid][0] << endl;
        else cout << "-1" << endl;
    }

    return 0;
}
