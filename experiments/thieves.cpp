#include<iostream>

using namespace std;

int main(){

    int i=7;
    int flag = 1;
    while(flag == 1){

        i+=7;
        if(i % 2 == 1 && i % 3 == 1 && i % 4 == 1 && i % 5 == 1 && i % 6 == 1) flag = 0;

    }
    cout<<i;
    return 0;
}
