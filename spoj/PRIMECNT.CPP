#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, a, b;

    cin >> n;
    while(n--){

        cin >> a >> b;
        //int primes[b - a + 1];

        vector<int> primes(b - a + 1, 1);

        //int *primes, SIZE = b - a + 1;
        //primes = (int*)malloc(sizeof(int) * SIZE);

        //fill_n(primes, b - a + 1, 1);
        if(a == 1) primes[0] = 0;

        for(int i = 2; i <= sqrt(b); i++){

            if(a % i == 0 && a != i) primes[0] = 0;
            for(int j = a+(i - (a % i)); j <= b; j += i){
                if(i != j) primes[j - a] = 0;
            }

        }

        int count = 0;
        for(int i = 0; i < b - a + 1; i++){

            if(primes[i] == 1){
                count++;
            }

        }

        cout << count << endl;

    }


    return 0;

}
