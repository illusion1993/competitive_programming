#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequenceLength(const vector<int> &A);
};

int Solution::longestSubsequenceLength(const vector<int> &A) {
    int this_dp_first, this_dp_second, ans = 0;
    vector<pair<int, int> > dp(A.size());
    if (dp.size()) {
        dp[0].first = 1;
        dp[0].second = 1;
        ans = 1;
    }

    for (int i = 1; i < A.size(); i++) {
        dp[i].first = 1;
        dp[i].second = 1;
        
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                dp[i].first = max(dp[i].first, dp[j].first + 1);
            }
            else if (A[j] > A[i]) {
                dp[i].second = max(dp[i].second, max(dp[j].first, dp[j].second) + 1);
            }
        }
        ans = max(ans, dp[i].first);
        ans = max(ans, dp[i].second);
    }
    return ans;
}

int main(int argc, char const *argv[])
{

    // Create Input
    vector<int> a;
    int n, tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        a.push_back(tmp);
    }

    // Create solution object
    Solution s;

    // create output container
    int ans;

    // call solution function
    ans = s.longestSubsequenceLength(a);

    // output answer
    cout << ans;

    return 0;
}    