#include <bits/stdc++.h>

using namespace std;

string rotate(string s, int pos, int k){

    string ans;
    for(int i = 0; i < pos; i++) ans += s[i];
    ans += s[pos + k - 1];
    for(int i = 1; i < k; i++) ans += s[pos + i - 1];
    for(int i = pos + k; i < s.length(); i++) ans += s[i];

    return ans;

}




int main(){

    int pos, k;
    string a;
    cin >> a >> pos >> k;
    cout << rotate(a, pos, k);

    return 0;

}
