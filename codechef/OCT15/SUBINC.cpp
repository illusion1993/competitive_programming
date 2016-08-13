#include <bits/stdc++.h>

using namespace std;

int main(){

    int t, n, a;

    cin >> t;
    while(t--){

        cin >> n;
        int arr, arr_prev, l_ind;
        long long dp, dp_prev;

        arr_prev = INT_MIN;
        dp_prev = 0;
        l_ind = -1;

        for(int i = 0; i < n; i++){
            cin >> arr;

            if(arr < arr_prev)
                    l_ind = i - 1;

            dp = dp_prev + i - l_ind;

            dp_prev = dp;
            arr_prev = arr;
        }

        cout << dp << endl;

    }



    return 0;

}
