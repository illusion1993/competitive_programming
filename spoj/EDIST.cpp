#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    string a, b;

    cin >> t;
    while(t--){

        cin >> a >> b;

        int dp[a.length() + 1][b.length() + 1];
        dp[0][0] = 0;
        for(int i = 1; i <= a.length(); i++){
            dp[i][0] = i;
        }
        for(int i = 1; i <= b.length(); i++){
            dp[0][i] = i;
        }

        for(int i = 1; i <= a.length(); i++){
            for(int j = 1; j <= b.length(); j++){

                //cout << "i is " << i << ", j is " << j << endl;

                if(a[i - 1] == b[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                    //cout << a[i - 1] << " = " << b[j - 1] << ", so dp[" << i << "][" << j << "] = dp[" << i - 1 << "][" << j - 1 << "]. i.e. " << dp[i][j] << endl;
                }

                else{
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]) + 1;

                    //cout << "putting dp[i][j] = " << dp[i][j] << endl;
                }

            }
        }
/*
        for(int i = 0; i <= a.length(); i++){
            for(int j = 0; j <= b.length(); j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
*/
        cout << dp[a.length()][b.length()] << "\n";

    }

    return 0;
}
