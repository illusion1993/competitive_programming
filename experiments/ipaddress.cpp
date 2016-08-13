#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(){

    string A = "0100100";
    vector<string> ans;
    string s;

    for(int i = 0; i <= 2; i++){
        for(int j = i+1; j <= i+3; j++){
            for(int k = j+1; k <= j+3; k++){

                if(k < A.length() - 1){
                    int p;
                    s = "";
                    for(p = 0; p <= i; p++) s += A[p];
                    s += '.';
                    for(p = i+1; p <= j; p++) s += A[p];
                    s += '.';
                    for(p = j+1; p <= k; p++) s += A[p];
                    s += '.';

                    while(p < A.length()){
                        s += A[p];
                        p++;
                    }

                    string part;
                    int ipart = 0;
                    bool right = true;

                    for(int a = 0; a < s.length(); a++){
                        if(s[a] == '.'){
                            //ipart = stoi(part, &sz);

                            for(int m = 0; m < part.size(); m++){
                                ipart += part[part.size() - m - 1] * pow(10, m);
                            }

                            if(part[0] == '0' && part.length() > 1) right = false;
                            if(ipart > 255) right = false;

                            cout << "part was " << part << endl;

                        }
                        else part += s[a];
                    }

                    if(right == true) ans.push_back(s);
                    //cout << endl << "value of k is " << k <<" length of A is " << A.length() << ", string is" << s;
                }

            }
        }

    }

    for(int i = 0; i < ans.size(); i++) cout << ans[i] << endl;

    return 0;

}
