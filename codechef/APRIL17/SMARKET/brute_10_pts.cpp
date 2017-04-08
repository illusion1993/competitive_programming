#include<bits/stdc++.h>
using namespace std;

int a[100000], n, q;

int count_order(int l, int r, int o) {
    int c = 1, ans;
    ans = (c == o) ? 1 : 0;
    for (int i = l + 1; i <= r; i++) {
        c = (a[i] == a[i - 1]) ? c + 1 : 1;
        if (c == o) ans++;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t, in, in1, in2;
    cin >> t;
    while(t--) {
        cin >> n >> q;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < q; i++) {
            cin >> in >> in1 >> in2;
            cout << count_order(in - 1, in1 - 1, in2) << "\n";
        }
    }

    return 0;
}
