#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(){
    string A, B;
    cin >> A >> B;



    long long power = 0, num = 0, asc;
    vector<long long> versionA, versionB;

    //if(A[A.length()-1] == '.') A.pop_back();
    //if(B[B.length()-1] == '.') B.pop_back();

    for(int i = A.length()-1; i >= 0; i--){
        if(A[i] != '.'){
            asc = (int)A[i] - 48;
            num += asc * pow(10, power);
            power++;
        }
        else{
            versionA.push_back(num);
            power = 0;
            num = 0;
        }
    }
    if(A[0] != '.') versionA.push_back(num);

    num = 0;
    power = 0;
    for(int i = B.length()-1; i >= 0; i--){
        if(B[i] != '.'){
            asc = (int)B[i] - 48;
            num += asc * pow(10, power);
            power++;
        }
        else{
            versionB.push_back(num);
            power = 0;
            num = 0;
        }
    }
    if(B[0] != '.') versionB.push_back(num);

    cout << endl << "displaying vectors: " << endl;
    for(int i = 0; i < versionA.size(); i++) cout << versionA[i] << " ";

    cout << endl << "displaying vectors: " << endl;
    for(int i = 0; i < versionB.size(); i++) cout << versionB[i] << " ";

    int ptr1, ptr2;
    ptr1 = versionA.size()-1;
    ptr2 = versionB.size()-1;

    while(versionA[ptr1] == versionB[ptr2] && ptr1 > 0 && ptr2 > 0){
        cout << endl << "Comparing " << versionA[ptr1] << " vs " << versionB[ptr2] << endl;
        ptr1--;
        ptr2--;
    }

    if(versionA[ptr1] == versionB[ptr2] && versionA.size() > versionB.size())
        cout << "1 case 1";
    else if(versionA[ptr1] == versionB[ptr2] && versionA.size() < versionB.size())
        cout << "-1 case 2";
    else if(versionA[ptr1] == versionB[ptr2] && versionA.size() == versionB.size())
        cout << "0 case 3";

    else if(versionA[ptr1] > versionB[ptr2])
        cout << "1 case 4";
    else if(versionA[ptr1] < versionB[ptr2])
        cout << "-1 case 5";


    return 0;

}
