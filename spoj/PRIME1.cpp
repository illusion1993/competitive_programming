#include <iostream>
using namespace std;

#define max 1000
#define LL long long

bool isPrime[max + 1];

void sieve(){

    for(LL i = 2; i <= max; i++) isPrime[i] = true;
    isPrime[0] = false;
    isPrime[1] = false;

    LL multiple;

    for(LL i = 2; i <= max; i++){

        if(isPrime[i]){
            multiple = i + i;

            while(multiple <= max){
                isPrime[multiple] = false;
                multiple += i;
            }

        }

    }

}

int main() {

    sieve();

    int t;
    LL m, n;

    cin >> t;

    while(t--){
        cin >> m >> n;

        for(LL i = m; i <= n; i++){
            if(isPrime[i]) cout << i << "\n";
        }

        cout << "\n";
    }

	return 0;
}
