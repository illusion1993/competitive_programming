#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(){

    string A;
    int B;

    cin >> A >> B;


    string ans = "";
    int pos;

    for(int i = 0; i < min(B, A.length()); i++){

        ans += A[i];
        cout << endl << "pushing " << A[i];

        pos = i;
        cout << endl << "Setting pos = " << pos;

        while(pos < A.length()){

            if((2*(B-1))-(2*i) > 0){
                pos = pos + (2*(B-1))-(2*i);

                cout << endl << "New pos = " << pos;

                if(pos < A.length()){
                    ans += A[pos];
                    cout << endl << "pushing " << A[pos];
                }

                else cout << endl << "New pos is not less than " << A.length();
            }

            if((2*i) > 0){
                pos = pos + (2*i);

                cout << endl << "New pos = " << pos;

                if(pos < A.length()){
                    ans += A[pos];
                    cout << endl << "pushing " << A[pos];
                }

                else cout << endl << "New pos is not less than " << A.length();
            }

        }

    }

    cout << endl << ans;


    return 0;

}
