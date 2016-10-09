#include <bits/stdc++.h>

using namespace std;

string convertToTitle(int A) {
    string ans;
    while (A) {
        //cout << "A % 26 = " << A % 26 << " A / 26 = " << A / 26 << " char appended is " << (char)((A % 26) + 64) << endl;
        if (A % 26 == 0){
            ans.insert(0, 1, 'Z');
            A = (A / 26) - 1;
        }
        else{
            ans.insert(0, 1, (char)((A % 26) + 64));
            A /= 26;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << convertToTitle(n);
    return 0;
}
