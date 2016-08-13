#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;

    cin >> n;
    int num, ans = 0;

    for(int i = 0; i < n - 1; i++){
        cin >> num;
        ans ^= num;
    }

    for(int i = 1; i < n + 1; i++){
        ans ^= i;
    }

    cout << ans;


    return 0;

}
