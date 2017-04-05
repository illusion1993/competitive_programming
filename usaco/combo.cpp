/*
ID: rathore1
PROG: combo
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;

int n, x[3], y[3], ans;

int dist(int a, int b) {
    int din, dout;
    din = abs(a - b);
    dout = (min(a, b) - 1) + (n - max(a, b)) + 1;
    return min(din, dout);
}

int main() {
    ofstream cout ("combo.out");
    ifstream cin ("combo.in");

    int inter = 1, c;
    cin >> n >> x[0] >> x[1] >> x[2] >> y[0] >> y[1] >> y[2];
    ans = 2 * pow(min(5, n), 3);

    for (int i = 0; i < 3; i++) {
        c = 0;
        for (int j = 1; j <= n; j++) {
            if (dist(j, x[i]) <= 2 && dist(j, y[i]) <= 2) c++;
        }
        inter *= c;
    }

    cout << ans - inter << endl;

    return 0;
}
