#include <bits/stdc++.h>

using namespace std;

bool isLength(long long n){
    if(n == 1) return true;

    else{
        n -= 1;
        if(n % 2 == 0 && (n / 2) % 2 == 1) return isLength(n / 2);

        else return false;
    }
}

int main(){

    //ifstream cin("A-small-practice.in");
    //ofstream cout("out-small.txt");

    int n, k, num = 1;
    cin >> n;

    while(n--){
        cin >> k;

        if((k-1) % 4 == 0) cout << "Case #" << num << ": 0" << endl;
        else if((k-3) % 4 == 0) cout << "Case #" << num << ": 1" << endl;
        else if(isLength(k-1)) cout << "Case #" << num << ": 0" << endl;
        else cout << "Case #" << num << ": 1" << endl;




        num++;
    }

}
