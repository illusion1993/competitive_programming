#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, in, arr[100];
    memset(arr, 0, sizeof(arr));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in;
        arr[in]++;
    }
    for (int i = 0; i < 100; i++) cout << arr[i] << " ";
    return 0;
}
