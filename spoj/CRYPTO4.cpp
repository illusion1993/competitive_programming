#include <bits/stdc++.h>
using namespace std;

int main() {

    int t, n;
    string a, b;
    char ch;

    cin >> t;

    while(t--){

        cin >> n >> a >> b;

        vector<int> k(n);
        vector<int> x(a.length());
        vector<int> y(b.length());

        for(int i = 0; i < a.length(); i++){
            ch = a[i];
            x[i] = ((int)ch - 65);
        }
        for(int i = 0; i < b.length(); i++){
            ch = b[i];
            y[i] = ((int)ch - 65);
        }

        for(int i = 0; i < a.length(); i++){
            cout << x[i] << ",";
        }
        cout << endl;
        for(int i = 0; i < b.length(); i++){
            cout << y[i] << ",";
        }
        cout << endl;
        for(int i = 0; i < k.size(); i++){
            cout << k[i] << ",";
        }

    }


	return 0;
}
