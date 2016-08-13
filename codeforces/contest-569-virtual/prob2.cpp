#include <iostream>

using namespace std;

int occ[100001] = {0}, serials[100001], n;

int findFirst(){

    for(int i = 1; i <= n; i++){
        if(occ[i] == 0) return i;
    }

}

int main(){

    int serial;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> serial;
        if(serial <= n){
            if(occ[serial] != 0){
                serial = findFirst();
            }

            occ[serial] = 1;
            serials[i] = serial;

        }
        else{
            serial = findFirst();
            occ[serial] = 1;
            serials[i] = serial;
        }
    }

    for(int i = 1; i <= n; i++) cout << serials[i] << " ";

    return 0;

}
