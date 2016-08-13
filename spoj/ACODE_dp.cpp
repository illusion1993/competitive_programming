#include <bits/stdc++.h>
using namespace std;

int main(){

    string code = "";
    vector<int> dp;

    cin >> code;
    while(code != "0"){

        dp.clear();
        dp.push_back(1);

        if(code.length() > 1){
            if((((int)code[0] - 48)*10) + (int)code[1] - 48 < 27 && code[1] != '0') dp.push_back(2);
            else dp.push_back(1);
        }

        for(int i = 2; i < code.length(); i++){
            dp.push_back(dp.back());

            if((((int)code[i-1] - 48)*10) + (int)code[i] - 48 < 27 && code[i-1] != '0') dp[i] += dp[i - 2];

            if(code[i] == '0'){
                if(code[i - 1] == '1' || code[i - 1] == '2'){
                    dp[i - 1] = dp[i - 2];
                    dp[i] = dp[i - 1];
                }
                else {
                    dp[i] = 0;
                    dp[i - 1] = 0;
                }
            }


        }
        if(code[0] != '0') cout << dp.back() << endl;
        else cout << "0" << endl;
        cin >> code;

    }

	return 0;

}
