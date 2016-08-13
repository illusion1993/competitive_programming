#include <bits/stdc++.h>
using namespace std;

void printTime(int counter){

    int h = counter / 60, m = counter % 60;

    if(h < 10) cout << "0";
    cout << h << ":";
    if(m < 10) cout << "0";
    cout << m << endl;

}

int main(){

    int t, counter;
    float a, angle;

    cin >> t;

    while(t--){

        cin >> a;

        counter = 0;
        angle = 0;
        while(counter < 60 * 12){

            if(abs(a - angle) < 1.0/120.0){
                printTime(counter);
            }

            else if(abs((360.0 - a) - angle) < 1.0/120.0){
                printTime(counter);
            }

            angle += 5.5;
            if(angle >= 360.0) angle -= 360.0;
            counter++;

        }

    }

    return 0;

}
