#include <iostream>

using namespace std;

int n, a[100], bribes = 0;

int maxIndex(){
    int max = 0;
    for(int i = 0; i < n; i++) if(a[i] > a[max]) max = i;

    return max;
}

void bribe(int maxIndex){

    for(int i = 0; i < n; i++){
        if(a[i] == a[maxIndex]){
            a[i]--;
            a[0]++;
            bribes++;
        }
    }

}

int main(){

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    if(maxIndex() != 0){
        while(maxIndex() != 0){
            bribe(maxIndex());
        }
    }

    cout << bribes;

    return 0;
}
