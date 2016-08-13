#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n, m, c;

    while(1){
        cin >> n;

        m = 1;
        c = 0;

        while(m != n){

            m++;
            if(m % 2 == 0) c++;

            if(m % 3 == 0) c++;

            if(m % 4 == 0) c++;

        }

        if(c > n) cout << c << "\n";
        else cout << n << "\n";

    }


	return 0;
}
