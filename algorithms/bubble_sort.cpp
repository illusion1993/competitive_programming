#include <bits/stdc++.h>

using namespace std;

int main(){

    int l, min;

    cin >> l;
    int *arr = (int*)malloc(l * sizeof(int));

    for(int i = 0; i < l; i++) cin >> arr[i];

    for(int i = l - 1; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            if(arr[j] > arr[i]){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    for(int i = 0; i < l; i++) cout << arr[i] << " ";

    return 0;

}
