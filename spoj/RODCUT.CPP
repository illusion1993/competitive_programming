#include <bits/stdc++.h>

using namespace std;

int main(){

    int t, l;
    long long n[41], sum;
    n[0] = 1;

    for(int i = 1; i < 41; i++){

        sum = 0;
        for(int j = 1; j <= i; j++){
            sum += n[i - j];
        }
        n[i] = sum;

    }

    cin >> t;
    while(t--){
        cin >> l;
        cout << n[l] << endl;
    }


    return 0;

}
