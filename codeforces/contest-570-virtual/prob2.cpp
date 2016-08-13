#include <iostream>

using namespace std;

int main(){

    unsigned m, n;
    cin >> n >> m;

    if(n != 1){
        if(n - m > m - 1) cout << m + 1;
        else if(n - m < m - 1) cout<< m - 1;
        else cout << m - 1;
    }

    else cout<< "1";

    return 0;

}
