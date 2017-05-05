#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin >> t; while (t--)

int sequence(char c) {
    return (c == 'C') ? 0 : (c == 'E') ? 1 : 2;
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    string s; bool okay;
    TC {
        cin >> s;
        okay = true;
        for (int i = 1; i < s.length(); i++) if (sequence(s[i]) < sequence(s[i - 1])) okay = false;
        cout << ((okay) ? "yes\n" : "no\n");
    }

    return 0;
}
