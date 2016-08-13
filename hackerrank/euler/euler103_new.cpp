#include <bits/stdc++.h>
using namespace std;

#define mod 715827881

int main(){

    int *b = (int*)malloc(1000001 * sizeof(int));
    int n, p, sum;

    b[0] = 1;
    b[1] = 1;

    cin >> n;

    p = 2;
    sum = 1;
    for(int i = 2; i <= n; i++){

        if(i % 2 == 0){
            b[i] = (2 * b[i - 1]) % mod;
        }

        else{
            b[i] = sum;
            sum = (sum - b[i - p]) % mod;
            p++;
        }

        sum = (sum + b[i]) % mod;
    }

    sum = 0;
    for(int i = 1; i <= n; i++){
        sum = (sum + b[n - i]) % mod;
        printf("%d ", sum);
    }

	return 0;

}
