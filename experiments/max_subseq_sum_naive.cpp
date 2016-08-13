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

    int sum, maxSum = INT_MIN;

    for(int i = 1; i <= l; i++){
        for(int j = 0; j <= l - i; j++){
            sum = 0;
            for(int k = j; k < i + j; k++){
                sum += a[k];
            }
            if(sum > maxSum) maxSum = sum;
        }
    }

    cout << maxSum;

    return 0;

}
