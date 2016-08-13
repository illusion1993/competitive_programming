#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    int A = 15, B = 9, t;

    if(A == 1 || B == 1) return 1;

    long long tmp, tmp1;

    A -= 1;
    B -= 1;

    if(A < B){
        t = A;
        A = B;
        B = t;
    }

    tmp = 1;
    tmp1 = 1;

    for(int i = A + 1; i <= A+B; i++){
        tmp *= i;
        cout << "tmp multiplied by " << i << " and became " << tmp << endl;
    }
    for(int i = 2; i <= B; i++){
        tmp1 *= i;
        cout << "tmp1 multiplied by " << i << " and became " << tmp1 << endl;
    }


    cout << tmp / tmp1;

    return 0;
}
