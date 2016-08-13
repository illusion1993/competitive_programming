#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<long long> sums, current;

    long long n, m, ai;

    cin >> n >> m;

    while(n--){

        cin >> ai;

        if(ai % m == 0){
            cout << "YES";
            return 0;
        }

        current.clear();
        current.push_back(ai);
        for(int i = 0; i < sums.size(); i++){
            if((ai + sums[i]) % m == 0){
                cout << "YES";
                return 0;
            }
            else{
                current.push_back(ai + sums[i]);
            }
        }
        sums = current;
    }

    cout << "NO";
    return 0;

}
