#include <bits/stdc++.h>
using namespace std;


int main() {
    int t, n, arr[10000], incr, diff;
    cin >> t;
    while(t--) {
        incr = 0;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n);
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                diff = arr[i] - arr[i-1];
                incr += diff / 5;
                diff %= 5;
                incr += diff / 2;
                diff %= 2;
                incr += diff;
                diff = 0;
            }
        }
        cout << incr << endl;
    }
    return 0;
}
