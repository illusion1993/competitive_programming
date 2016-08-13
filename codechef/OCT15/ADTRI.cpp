#include <bits/stdc++.h>

using namespace std;

int main(){

    int t, n, b;
    int sq;

    cin >> t;
    while(t--){

        cin >> n;
        bool found = false;
        for(int i = 1; i < n; i++){

            sq = ((long long)n * (long long)n) - ((long long)i * (long long)i);
            b = (int)sqrt(sq);

            if(sq == (long long)b * (long long)b){
                found = true;
                break;
            }

        }

        if(found) cout << "YES";
        else cout << "NO";

        cout << endl;

    }

    return 0;

}
