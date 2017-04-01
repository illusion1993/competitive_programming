#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for(int x_i = 0;x_i < n;x_i++){
       cin >> x[x_i];
    }
    sort(x.begin(), x.end());
    
    int radios = 0, prev = -1;
    for (int i = 0; i < x.size(); i++) {
        if (!radios || x[i] > prev + k) {
            int j = i;
            while(j < x.size() && x[j] <= x[i] + k) j++;
            prev = x[j - 1];
            radios++;
            i = j;
        }
    }
    cout << radios;
    
    return 0;
}
