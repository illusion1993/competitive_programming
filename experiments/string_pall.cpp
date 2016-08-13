#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    string A = "A man, a plan, a canal: Panama";

    int ptr1 = 0, ptr2 = A.length()-1;

    while(ptr1 < ptr2){

        if(isalpha(A[ptr1]) && isalpha(A[ptr2])){
            if(tolower(A[ptr1]) != tolower(A[ptr2])){
                cout << endl << tolower(A[ptr1]) << " not same as " << tolower(A[ptr2]);
            }
            else{
                ptr1++;
                ptr2--;
            }
        }

        if(!isalpha(A[ptr1])) ptr1++;
        if(!isalpha(A[ptr2])) ptr2--;

    //cout << A[ptr1] << endl << A[ptr2];

    }

    //cout << 1;

    return 0;

}
