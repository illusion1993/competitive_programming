#include <bits/stdc++.h>

using namespace std;

int main(){

    int a[]  = {-10,-10,1,3,2};
    int l = 5;

    int p, q, r;
    p = abs(a[0]);
    q = abs(a[1]);
    r = abs(a[2]);

    for(int i = 3; i < l; i++){

        if(abs(a[i]) > p || abs(a[i]) > q || abs(a[i]) > r){
            if(p <= q && p <= r) p = abs(a[i]);
            else if(q < p && q <= r) q = abs(a[i]);
            else if(r < p && r < q) r = abs(a[i]);
        }

    }

    cout << p * q * r << endl;

    return 0;

}
