#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
 
    char prev = s[0];
    int count = 1, pals = 1, amaz_index = 1;

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            count++;
        }
        else {
            pals += (count * (count - 1)) / 2;
            count = 1;
            amaz_index++;
        }
        pals += (amaz_index + (amaz_index % 2)) / 2;
    }
    if (count > 1) pals += (count * (count - 1)) / 2;

    cout << pals;
    
    return 0;
}
 