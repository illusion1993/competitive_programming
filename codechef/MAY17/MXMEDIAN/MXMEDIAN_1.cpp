#include<bits/stdc++.h>
using namespace std;
#define TC int t; cin >> t; while (t--)

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n;

    TC {
        cin >> n;
        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        cout << a[n + (n / 2)] << "\n";
        for (int i = 0; i < n; i++) cout << a[i] << " " << a[n + i] << " ";
        cout << "\n";
    }

    return 0;
}
