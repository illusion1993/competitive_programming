#include<bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));
    int t, n;
    t = 2;
    n = 5;

    cout << t << "\n";
    while(t--) {
        cout << n << "\n";
        for (int i = 1; i < 4; i++) {
            for (int j = 0; j < n - i; j++) cout << (rand() % 20) + 1 << " ";
            cout << "\n";
        }
    }

    return 0;
}
