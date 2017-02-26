#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    string a;
    int k, zero_count = 0, pos;
    cin >> a >> k;

    pos = a.length();
    while(pos > -1 && zero_count != k) {
        pos--;
        if (a[pos] == '0') zero_count++;
    }

    if (zero_count != k) cout << a.length() - 1;
    else cout << a.length() - pos - k;

    return 0;
}
