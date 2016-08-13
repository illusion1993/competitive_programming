#include <bits/stdc++.h>

using namespace std;

int main(){


    bool prime;

    vector<int> p, d, dd, ddd;

    for(long long i = 2; i <= 100 ; i++){

        prime = true;
        for(long long j = 2; j < i; j++){
            if(i % j == 0){
                prime = false;
                break;
            }
        }

        if(prime){
            p.push_back((int)i);
        }

    }

    for(int i = 1; i < p.size(); i++) d.push_back(p[i] - p[i-1]);
    for(int i = 1; i < d.size(); i++) dd.push_back(d[i] - d[i-1]);
    for(int i = 1; i < dd.size(); i++) ddd.push_back(dd[i] - dd[i-1]);

    for(int i = 0; i < p.size(); i++) cout << p[i] << " ";
    cout << endl;
    for(int i = 0; i < d.size(); i++) cout << d[i] << " ";
    cout << endl;
    for(int i = 0; i < dd.size(); i++) cout << dd[i] << " ";
    cout << endl;
    for(int i = 0; i < ddd.size(); i++) cout << ddd[i] << " ";
    cout << endl;

    return 0;
}
