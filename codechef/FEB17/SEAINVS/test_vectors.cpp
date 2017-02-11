#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<vector<int> > a(3, vector<int>(2, 0));

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}
