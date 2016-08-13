#include <bits/stdc++.h>

using namespace std;

int main(){

    //ifstream cin("A-small-practice.in");
    //ofstream cout("out-small.txt");

    int t, n, m, l, r, D;
    float volume, edge, a;
    vector<float> dimensions;

    cin >> t;
    while(t--){
        dimensions.clear();
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> a;
            dimensions.push_back(a);
        }
        while(m--){
            volume = 1;
            cin >> l >> r;
            for(int i = l; i <= r; i++) volume *= dimensions[i];

            D = r - l + 1;
            edge = pow(volume, (1.0/(float)D));

            cout<< setprecision(9) << edge << endl;
        }
    }

}
