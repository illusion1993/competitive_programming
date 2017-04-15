#include<bits/stdc++.h>
using namespace std;

int c;
string s;

bool isPal(int a, int b) {
    bool ans = true;
    if (a == b) return ans;
    string sn;

    sn += s[a];
    for (int i = a + 1; i <= b; i++) {
        if (sn[sn.length() - 1] != s[i]) sn += s[i];
    }

    for (int i = 0; i <= sn.length() / 2 && ans; i++) {
        if (sn[i] != sn[sn.length() - i - 1]) {
            ans = false;
        }
    }
    return ans;
}

void calc() {
    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            if (isPal(i, j)) {
                c++;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    c = 0;
 
    calc();
    cout << c;
    
    return 0;
}
 