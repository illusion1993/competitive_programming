#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<int> dp, coins;
    int sum = 13;

    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(3);

    dp.push_back(0);

    for(int i = 1; i <= sum; i++){
        int dp_min = INT_MAX;

        for(int j = 0; j < coins.size(); j++){
            if(i - coins[j] >= 0 && dp[i - coins[j]] < dp_min) dp_min = dp[i - coins[j]];
        }

        dp.push_back(dp_min + 1);
    }

    for(int i = 0; i < dp.size(); i++) cout << dp[i] << " ";

    return 0;

}
