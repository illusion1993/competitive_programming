#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(){

    string A;
    //cin >> A;
    A = " xx-88297 248252140B12 37239U4622733246I218 ";


    string s = "";
    bool on = true, negative = false;
    char ch;

    long long total = 0, val;

    for(int i = 0; i < A.length(); i++){
        ch = A[i];
        val = ((long long)ch) - 48;

        if(val >= 0 && val <= 9){
            if(on){
                s += ch;
            }
        }

        else{

            if(s.length() > 0){
                on = false;
            }
            else if(s.length() == 0 && ch =='-' && (int)A[i+1] >= 48 && (int)A[i+1] <= 57){
                negative = true;
            }

        }
    }

    for(int i = 0; i < s.length(); i++){
        ch = s[s.length()-1-i];
        val = ((long long)ch) - 48;
        total += val * pow(10, i);
    }

    // INT_MAX check
    if(negative) cout << "-";
    cout << s;


    return 0;

}
