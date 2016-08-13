#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, s;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> s;

    int ptr = 0;
    while(s > 0){
        s -= a[ptr % n];
        ptr++;
    }

    cout << ptr;

    return 0;

}
