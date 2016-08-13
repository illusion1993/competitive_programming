/*
ID: rathore1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int makeInt(char ch){
    int n = (int)ch;
    return n-64;
}

int product(string s){
    int p = 1;
    for(int i=0; i<s.length(); i++) p*=makeInt(s[i]);
    return p;
}

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    fin >> a >> b;
    if(product(a) % 47 == product(b) % 47) fout << "GO" << endl;
    else fout << "STAY" << endl;
    return 0;
}
