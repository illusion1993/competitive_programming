#include <bits/stdc++.h>
using namespace std;

string increment(string s){

    int n, carry = 1, l = s.length();
    string ans;

    for(int i = 0; i < l; i++){
        n = (int)s[l - i - 1] - 48;
        n += carry;
        carry = n / 10;
        n %= 10;

        ans = (char)(n + 48) + ans;
    }

    if(carry != 0) ans = (char)(carry + 48) + ans;

    return ans;

}

string compare(string a, string b, char m){

    string ans;
    reverse(a.begin(), a.end());
    int nines = 0, l = a.length();

    for(int i = 0; i < l; i++){
        if(a[i] == '9' && b[i] == '9') nines++;
    }


    if(nines == l && (m == '9' || m == '\0')){
        ans = "1";
        for(int i = 0; i < (2*l) - 1; i++) ans += '0';
        if(m == '9') ans += '0';
        ans += '1';
    }

    else{
        if(a > b){
            b = a;
            reverse(a.begin(), a.end());
        }

        else{

            if(m == '9'){
                m = '0';
                reverse(a.begin(), a.end());
                a = increment(a);
                reverse(a.begin(), a.end());
                b = a;
                reverse(a.begin(), a.end());
            }
            else{

                if(m != '\0'){
                    m++;
                    b = a;
                    reverse(a.begin(), a.end());
                }

                else{
                    reverse(a.begin(), a.end());
                    a = increment(a);
                    reverse(a.begin(), a.end());
                    b = a;
                    reverse(a.begin(), a.end());
                }
            }

        }

        ans += a;
        if(m != '\0') ans += m;
        ans += b;

    }

    return ans;

}

int main() {

    int t, l;
    string a, b, ans;
    char m;

    cin >> t;
    while(t--){
        cin >> ans;
        l = ans.length();
        if(l % 2 == 0){
            a = ans.substr(0, l/2);
            b = ans.substr(l/2, l/2);
            m = '\0';
        }
        else{
            m = ans[l/2];
            a = ans.substr(0, l/2);
            b = ans.substr((l/2) + 1, l/2);
        }

        ans = compare(a, b, m);

        cout << ans << endl;
    }

	return 0;
}
