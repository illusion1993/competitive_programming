#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long ai[200000];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ai[i];
    }

    for (int i = 0; i < n; i++) {
        if (i < n/2) {
            if (i % 2) cout << ai[i];
            else cout << ai[n - 1 - i];
        }
        else {
            if ((n - i - 1) % 2) cout << ai[i];
            else cout << ai[n - 1 - i];
        }
        cout << " ";
    }
}
