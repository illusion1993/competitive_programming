#include <bits/stdc++.h>
using namespace std;

int main() {

    int t, x, y;

    cin >> t;

    while(t--){

        cin >> x >> y;

        if(x == y)
            cout << ((x / 2) * 4) + (x % 2) << endl;

        else if(x - y == 2)
            cout << (((x / 2) - 1) * 4) + 2 + (x % 2) << endl;

        else
            cout << "No Number" << endl;

    }


	return 0;
}
