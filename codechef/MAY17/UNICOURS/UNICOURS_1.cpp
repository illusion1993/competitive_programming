#include<bits/stdc++.h>
using namespace std;
#define TC int t; cin >> t; while (t--)

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, max_req;
    TC {
        cin >> n;
        max_req = 0;
        for (int i = 0; i < n; i++) {
            cin >> a;
            max_req = max(max_req, a);
        }
        cout << n - max_req << "\n";
    }

    return 0;
}
