#include <bits/stdc++.h>

using namespace std;

int n;
long long *p, *a, *h, *dp;
int *from;

void findMinCost(int n){

    long long cost = LLONG_MAX, cur;

    int ptr = n - 1;

    while(ptr >= 0 && p[ptr] > p[n]) ptr--;

    while(ptr != -1){

        cur = dp[ptr] + a[n] + ((h[n] - h[ptr]) * (h[n] - h[ptr]));
        if(cur < cost){
            cost = cur;
            from[n] = ptr;
        }

        ptr = from[ptr];

    }

    dp[n] = cost;

}

int main(){

    cin >> n;
    p = (long long*)malloc(n * sizeof(long long));
    a = (long long*)malloc(n * sizeof(long long));
    h = (long long*)malloc(n * sizeof(long long));
    dp = (long long*)malloc(n * sizeof(long long));
    from = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        cin >> h[i];
        dp[i] = LLONG_MAX;
    }

    dp[0] = a[0];
    from[0] = -1;

    for(int i = 1; i < n; i++) findMinCost(i);
    cout << dp[n - 1];

    return 0;

}
