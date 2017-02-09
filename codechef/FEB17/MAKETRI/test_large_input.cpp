#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    long long a[1000000], l, h;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            l = max(a[i], a[j]) - min(a[i], a[j]) + 1;
            h = a[i] + a[j] - 1;
        }
        //cout << "Done for " << i + 1 << "th input" << endl;
    }

    return 0;
}
