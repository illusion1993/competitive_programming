#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int main(){

    vector<int> A, B, C;
    A.push_back(1);
    A.push_back(4);
    A.push_back(10);

    B.push_back(2);
    B.push_back(15);
    B.push_back(20);

    C.push_back(10);
    C.push_back(12);













    vector<int> data, map;
    int ptr1=0, ptr2=0, ptr3=0, min = INT_MAX, largest;

    while(data.size() < A.size() + B.size() + C.size()){

        cout << "running merge" << endl << "Vector Now: ";
        for(int i = 0; i < data.size(); i++) cout << data[i] << " ";
        cout << endl;

        if(ptr1 < A.size()){
            // A is remaining
            if(ptr2 < B.size()){
                // B is remaining
                if(ptr3 < C.size()){
                    // C is remaining

                    if(A[ptr1] <= B[ptr2] && A[ptr1] <= C[ptr3]){
                        data.push_back(A[ptr1]);
                        map.push_back(0);
                        ptr1++;
                    }
                    else if(B[ptr2] <= A[ptr1] && B[ptr2] <= C[ptr3]){
                        data.push_back(B[ptr2]);
                        map.push_back(1);
                        ptr2++;
                    }
                    else if(C[ptr3] <= B[ptr2] && C[ptr3] <= A[ptr1]){
                        data.push_back(C[ptr3]);
                        map.push_back(2);
                        ptr3++;
                    }

                }
                else{
                    // C is not remaining
                    if(B[ptr2] <= A[ptr1]){
                        data.push_back(B[ptr2]);
                        map.push_back(1);
                        ptr2++;
                    }
                    else{
                        data.push_back(A[ptr1]);
                        map.push_back(0);
                        ptr1++;
                    }
                }

            }
            else{
                // B is not remaining
                if(ptr3 < C.size()){
                    // C is remaining
                    if(A[ptr1] <= C[ptr3]){
                        data.push_back(A[ptr1]);
                        map.push_back(0);
                        ptr1++;
                    }
                    else{
                        data.push_back(C[ptr3]);
                        map.push_back(2);
                        ptr3++;
                    }
                }
                else{
                    // C is not remaining
                    data.push_back(A[ptr1]);
                    map.push_back(0);
                    ptr1++;
                }
            }
        }
        else{
            // A is not remaining
            if(ptr2 < B.size()){
                // B is remaining
                if(ptr3 < C.size()){
                    // C is remaining
                    if(B[ptr2] <= C[ptr3]){
                        data.push_back(B[ptr2]);
                        map.push_back(1);
                        ptr2++;
                    }
                    else{
                        data.push_back(C[ptr3]);
                        map.push_back(2);
                        ptr3++;
                    }

                }
                else{
                    // C is not remaining
                    data.push_back(B[ptr2]);
                    map.push_back(1);
                    ptr2++;
                }
            }
            else{
                // B is not remaining
                data.push_back(C[ptr3]);
                map.push_back(2);
                ptr3++;
            }
        }

    }

    bool f, s, t;
    int fin;
    for(int i = 0; i <= data.size()-3; i++){
        f = false;
        s = false;
        t = false;
        fin = i;

        while(f == false || s == false || t == false){
            if(map[fin] == 0) f = true;
            else if(map[fin] == 1) s = true;
            else if(map[fin] == 2) t = true;

            fin++;
        }

        if(min > data[fin] - data[i]) min = data[fin] - data[i];
    }

    return min;

}
