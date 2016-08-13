#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(){

    string A;
    cin >> A;

    char rom[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int dec[7] = {1, 5, 10, 50, 100, 500, 1000};

    char ch;
    int thispos, thisval, lastval = 0, total = 0;

    for(int i = 0; i < A.length(); i++){
        ch = A[A.length() - 1 - i];

        thispos = 0;
        while(rom[thispos] != ch) thispos++;

        thisval = dec[thispos];

        if(thisval >= lastval) total += thisval;
        else total -= thisval;

        lastval = thisval;
    }

    cout << total;

    return 0;

}
