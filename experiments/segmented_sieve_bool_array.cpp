#include<bits/stdc++.h>
using namespace std;

void checkBy(long long a, bool *isPrime, long long m, long long n){

    long long l = n - m + 1;

    /*
    for(long long i = 0; i < l; i++){
        if(isPrime[i] == 1){
            if((i + m) % a == 0 && (i + m) != a){
                isPrime[i] = 0;
            }

            if(i + m == 0 || i + m == 1) isPrime[i] = 0;
        }
    }
    */
    long long s = 2*(a - (m % a));
    while(s <= n){
        isPrime[s] = 0;
        s += a;
    }

}

int main(){

    int t;
    long long m, n;

    cin >> t;
    while(t--){

        cin >> m >> n;
        bool isPrime[n - m + 1];

        for(long long i = m; i <= n; i++) isPrime[i - m] = 1;
        /*
        if(m == 0){
            isPrime[0] = 0;
            if(n >= 1) isPrime[1] = 0;
        }
        else if(m == 1){
            isPrime[0] = 0;
        }
        */

        for(long long i = 2; i < sqrt(n); i++){
            checkBy(i, isPrime, m, n);
        }

        for(long long i = 0; i < n - m + 1; i++){
            if(isPrime[i] == 1) cout << i + m << endl;
        }

    }

	return 0;

}
