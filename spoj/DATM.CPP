#include <bits/stdc++.h>

using namespace std;

int main(){

    int t, a, b;
    cin >> t;

    while(t--){
        cin >> a >> b;
        a -= b + ((b / 500) * 10);
        if(a >= 0) cout << a << endl;
        else cout << "Sorry" << endl;
    }


    return 0;

}
