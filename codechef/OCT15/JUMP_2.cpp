#include <bits/stdc++.h>

using namespace std;

int n;
long long *p, *a, *h, *dp;

void findMinCost(int n){

    long long cost = LLONG_MAX, cur;

    for(int i = n - 1; i >= 0; i--){
        if(p[i] < p[n] && dp[i] != LLONG_MAX){
            cur = dp[i] + a[n] + ((h[n] - h[i]) * (h[n] - h[i]));
            if(cur < cost) cost = cur;
        }
    }

    dp[n] = cost;

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
    for(int i = 1; i < n; i++) findMinCost(i);

    cout << dp[n - 1];

    return 0;

}
