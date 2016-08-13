#include <bits/stdc++.h>

using namespace std;

int n;
long long *p, *a, *h, *dp;

long long findMinCost(int n){

    if(dp[n] != LLONG_MAX) return dp[n];

    long long cost = LLONG_MAX, cur;

    for(int i = n; i >= 0; i--){
        if(p[i] < p[n]){
            cur = findMinCost(i);
            cur = cur + a[n] + ((h[n] - h[i]) * (h[n] - h[i]));
            if(cur < cost) cost = cur;
        }
    }

    dp[n] = cost;
    return cost;

}

int main(){

    cin >> n;
    p = (long long*)malloc(n * sizeof(long long));
    a = (long long*)malloc(n * sizeof(long long));
    h = (long long*)malloc(n * sizeof(long long));
    dp = (long long*)malloc(n * sizeof(long long));

    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        cin >> h[i];
        dp[i] = LLONG_MAX;
    }

    dp[0] = a[0];

    cout << findMinCost(n - 1);

    return 0;

}
