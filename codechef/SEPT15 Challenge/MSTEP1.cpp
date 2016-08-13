#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){

    int t, n, val, steps;
    cin >> t;

    while(t--){

        cin >> n;
        steps = 0;

        vector<int> x((n*n), 0);
        vector<int> y((n*n), 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> val;
                x[val-1] = i;
                y[val-1] = j;
            }
        }

        for(int i = 1; i < n*n; i++){
            steps += abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]);
        }

        cout << steps << endl;

    }



    return 0;

}
