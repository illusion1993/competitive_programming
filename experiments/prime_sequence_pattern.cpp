#include <bits/stdc++.h>

using namespace std;


bool isPrime(int n){

    bool prime = true;

    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            prime = false;
            break;
        }
    }

    return prime;

}

void primeFactorize(int n, vector<int> &factors){

    //cout << "Finding prime factors of " << n << endl;

    if(n == 2){
        //cout << "       if 2, push 2" << endl;
        factors.push_back(2);
    }

    else{
        for(int i = 2; i <= n; i++){

            //cout << "   Trying " << i << " as a factor." << endl;
            if(isPrime(i) && n % i == 0){
                //cout << "   " << i << " is prime factor of " << n << " n will become " << n/i << " now." << endl;
                factors.push_back(i);
                n /= i;

                primeFactorize(n, factors);
                break;
            }

        }
    }

}


int main(){

    cout << "(1 x 1) + 1 = 2" << endl << "(1 x 2) + 1 = 3" << endl;

    vector<int> factors;

    for(int i = 4; i < 100; i++){

        //if(isPrime(i)){
            factors.clear();
            //cout << i << " is prime, factorizing " << i-1 << endl;
            primeFactorize(i-1, factors);

            cout << "(" << factors[0] << " ";
            for(int j = 1; j < factors.size(); j++){
                cout << "x " << factors[j] ;
                if(j < factors.size()-1) cout << " ";
            }
            cout << ") + 1 = " << i ;
            if(isPrime(i)) cout << " -------------------------P";
            cout << endl;

        //}

    }



    return 0;
}
