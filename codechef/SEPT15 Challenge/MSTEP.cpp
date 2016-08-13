#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){

    int t, n, x, y, val, steps;
    cin >> t;

    while(t--){
        steps = 0;
        cin >> n;
        vector< vector<int> > v;
        vector<int> vv;

        for(int i = 0; i < n; i++){
            vv.clear();
            for(int j = 0; j < n; j++){

                cin >> val;
                vv.push_back(val);

                if(val == 1){
                    x = i;
                    y = j;
                }

            }
            v.push_back(vv);
        }

        for(int a = 2; a <= n * n; a++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(v[i][j] == a){
                        steps += abs(i-x) + abs(j-y);
                        x = i;
                        y = j;

                        goto endloop;
                    }
                }
            }
            endloop:;
        }

        cout << steps << endl;

    }



    return 0;

}
