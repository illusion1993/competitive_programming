#include <bits/stdc++.h>

using namespace std;

int main(){

    int l, e;
    vector<int> a;
    cin >> l;
    for(int i = 0; i < l; i++){
        e = rand() * pow(-1, (rand() % 2));
        a.push_back(e);
    }

    vector<int> s;

    s.push_back(a[0]);
    for(int i = 1; i < l; i++){
        s.push_back(max(a[i], s.back() + a[i]));
    }

    int maxSum = INT_MIN;

    for(int i = 0; i < l; i++){
        if(s[i] > maxSum) maxSum = s[i];
    }

    cout << maxSum;


    return 0;

}
