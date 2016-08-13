#include <iostream>

using namespace std;

int main(){

    float t, s, q, clash;
    int plays = 0;
    cin >> t >> s >> q;

    clash = s;

    while(clash < t){
        clash = clash + (clash * (q - 1));
        plays++;
    }

    cout << plays;

    return 0;

}
