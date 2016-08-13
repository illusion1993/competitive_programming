#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m, last = 0;
    cin >> n >> m;

    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++) a[i] = ceil((float)a[i]/m);

    for(int i = 0; i < n; i++){
        if(a[i] >= a[last]) last = i;
    }

    cout << last + 1;

    return 0;
}
