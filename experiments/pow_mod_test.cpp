#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){

    int x, n, d;
    cin >> x >> n >> d;
    ////////////////////////////////////////////////

    int m = sqrt(n);
    while(n % m != 0) m--;

    x = x % d;
    cout << x << endl << m;

    ///////////////////////////////////////////////

    return 0;

}
