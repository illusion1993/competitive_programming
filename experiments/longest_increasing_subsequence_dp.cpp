#include <bits/stdc++.h>

using namespace std;

int main(){

    int l, e;
    vector<int> a;

    cin >> l;
    for(int i = 0; i < l; i++){
        e = abs(rand());
        //cin >> e;
        a.push_back(e);
    }

    vector<int> L;
    L.push_back(1);

    for(int i = 1; i < l; i++){
        int maxPrev = INT_MIN;
        bool found = false;
        for(int j = i - 1; j >= 0; j--){
            if(a[j] < a[i] && L[j] > maxPrev){
                maxPrev = L[j];
                found = true;
            }
        }

        if(found){
            L.push_back(maxPrev + 1);
        }
        else{
            L.push_back(1);
        }
    }

    for(int i = 0; i < L.size(); i++) cout << L[i] << ",";

    return 0;

}
