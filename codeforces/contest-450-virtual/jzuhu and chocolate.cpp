#include <bits/stdc++.h>

using namespace std;

int main(){

    long long max = 0, area, n, m, k, c;

    cin >> n >> m >> k;

    if(k > (n-1)*(m-1)) cout << "-1";
    else{

        vector<long long> v;
        for(int i = 1; i*i <= n; ++i)
            v.push_back(i),v.push_back(n/i);

        cout << max;
    }

    return 0;
}
