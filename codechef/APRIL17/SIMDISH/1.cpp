#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    string s;
    map<string, bool> occ;
    cin >> t;
    while(t--) {
        occ.clear();
        for (int i = 0; i < 8; i++) {
            cin >> s;
            occ[s] = true;
        }
        cout << ((occ.size() <= 6) ? "similar\n" : "dissimilar\n");
    }

    return 0;
}
