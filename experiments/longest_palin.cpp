#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(){
    string A;
    cin >> A;



    string longest="", current="";

    for(int i = 0; i < A.length(); i++){

        int j = A.length()-1;
        bool found = false;

        while(j >= i && !found){

            //cout << endl << "Cheking from " << i << " to " <<j;

            if(A[j] == A[i]){
                //cout << endl << "First char matched";
                int ptr1 = i, ptr2 = j;

                while(A[ptr1] == A[ptr2] && ptr1 <= ptr2){
                    ptr1++;
                    ptr2--;
                }

                if(ptr1 > ptr2){

                    found = true;
                    current = "";

                    for(int a = i; a <= j; a++) current += A[a];

                    cout << endl << "A palin found - " << current;

                    if(current.length() > longest.length()) longest = current;
                }
            }
            j--;
        }
    }

    cout << endl <<endl<<longest;




    return 0;

}
