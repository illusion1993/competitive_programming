#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string A);
};

int Solution::numDecodings(string A) {
    int dp[A.length() + 1];
    dp[0] = 1;
    dp[1] = (A[0] != '0');
    
    for (int i = 1; i < A.length(); i++) {
        if (dp[i] == 0) dp[i + 1] = 0;
        else if (A[i] == '0') dp[i + 1] = (A[i - 1] != '1' && A[i - 1] != '2') ? 0 : dp[i - 1];
        else {
            dp[i + 1] = dp[i];
            if (A[i] - 1 == '1' || (A[i - 1] == '2' && A[i] >= '0' && A[i] <= '6')) dp[i + 1] += dp[i - 1];
        }
    }
    return dp[A.length()];
}


int main(int argc, char const *argv[])
{

    // Create Input
    string a;
    cin >> a;

    // Create solution object
    Solution s;

    // create output container
    int ans;

    // call solution function
    ans = s.numDecodings(a);

    // output answer
    cout << ans;

    return 0;
}    