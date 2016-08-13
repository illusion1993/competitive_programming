#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){

    int x, n, d;
    cin >> x >> n >> d;
    ////////////////////////////////////////////////


    if(x == 0) return 0;

    int m = sqrt(n);
    while(n % m != 0) m--;

    long long mult = 1, mult2 = 1;
    for(int i = 1; i <= m; i++){
        mult = (mult * (long long)x) % (long long)d;
    }

    for(int i = m+1; i <= n/m; i++){
        mult2 = (mult2 * mult) % (long long)d;
    }
    if(m == n) mult2 = mult;

    cout << "mult " << mult << " mult 2 " << mult2 << " ans " << (int)mult2 % d;

    if(mult2 < 0) return d + ((int)mult2 % d);
    return (int)mult2 % d;

    ///////////////////////////////////////////////

    return 0;

}
