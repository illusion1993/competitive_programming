#include <bits/stdc++.h>

using namespace std;

int main(){

    int l, min;

    cin >> l;
    int *arr = (int*)malloc(l * sizeof(int));

    for(int i = 0; i < l; i++) cin >> arr[i];

    for(int i = 0; i < l - 1; i++){

        min = i;

        for(int j = i; j < l; j++){
            if(arr[j] < arr[min]) min = j;
        }

        int tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;

    }

    for(int i = 0; i < l; i++) cout << arr[i] << " ";

    return 0;

}
