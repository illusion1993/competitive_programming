#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compareNum(string a, string b) {
    cout << "a + b is : " << a+b << endl;
    cout << "b + a is : " << b+a << endl;
    return a + b > b + a;
}

int main(){

    string a, b;
    while(1){
        cin >> a >> b;
        if(compareNum(a, b)) cout << a << endl;
        else cout << b << endl;
    }



    return 0;

}
