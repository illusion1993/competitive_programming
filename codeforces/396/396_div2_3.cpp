#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, a[26], freq[26];
    string s;

    cin >> n >> s;
    for (int i = 0; i < 26; i++) cin >> a[i];
    memset(freq, 0, sizeof(freq));

    for (int i = 0; i < s.length(); i++) {
        freq[(int)s[i] - 97]++;
        if (freq[(int)s[i] - 97] == a[(int)s[i] - 97]) {

            // find all possible groups till length i + 1

            memset(freq, 0, sizeof(freq));
        }
    }

    return 0;
}
