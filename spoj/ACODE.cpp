#include <bits/stdc++.h>
using namespace std;

long long countCodes(string code, int pos){

    if(pos >= code.length() - 1) return 1;

    else{
        if(code[pos] < '3' && code[pos + 1] < '7'){
            return countCodes(code, pos + 1) + countCodes(code, pos + 2);
        }

        else return countCodes(code, pos + 1);
    }

}

int main(){

    string code = "";
    long long n;

    while(code != "0"){
        cin >> code;
        n = countCodes(code, 0);
        cout << n << endl;
    }

	return 0;

}
