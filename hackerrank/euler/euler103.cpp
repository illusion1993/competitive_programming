#include <bits/stdc++.h>
using namespace std;

#define mod 715827881

int main(){

    //vector<int> a;
    int *a = (int*)malloc(1000001 * sizeof(int));
    int n, l = 1, m;
    //a.push_back(1);
    a[0] = 1;

    cin >> n;

    for(int i = 1; i < n; i++){
        m = a[(l - 1) / 2];
        //a.push_back(m);
        a[l] = m;
        for(int j = 0; j < l; j++) a[j] = (a[j] + m) % mod;
        l++;

        //for(int i = 0; i < l; i++) printf("%d ", a[l - 1 - i]);
        cout << a[(l - 1) / 2];
        cout << endl;

    }

    for(int i = 0; i < l; i++) printf("%d ", a[l - 1 - i]);

	return 0;

}
