#include <bits/stdc++.h>

using namespace std;

int main(){

    int t, n, c, max_win;
    string a, b;

    cin >> t;

    while(t--){

        cin >> n >> a >> b;
        c = 0;
        max_win = INT_MIN;

        int w[n + 1];

        for(int i = 0; i <= n; i++) cin >> w[i];

        for(int i = 0; i < a.length(); i++){
            if(a[i] == b[i]) c++;
        }

        if(c == a.length()) cout << w[c] << endl;
        else{
            for(int i = 0; i <= c; i++) max_win = max(max_win, w[i]);

            cout << max_win << endl;
        }

    }

    return 0;

}
