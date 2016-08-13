#include <bits/stdc++.h>
using namespace std;

long long dp(long long n){

    if(n == 0) return 0;
    else if(n == 1) return 1;

    else{
        return max(n, dp(n/2) + dp(n/3) + dp(n/4));
    }

}

int main() {

    long long n, p, l;

    int *c = (int*)malloc(1000000000 * sizeof(int));
    c[0] = 0;
    c[1] = 1;
    l = 2;

    while(1){

        cin >> n;

        if(n > l - 1){

            for(long long i = l; i <= n; i++){
                p = c[i / 2] + c[i / 3] + c[i / 4];
                c[i] = max(p, i);
                l++;
            }

        }

        cout << c[n] << endl;

    }


	return 0;
}
