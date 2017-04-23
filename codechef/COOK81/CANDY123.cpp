#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int t, a, b, c;
    bool over, a_lose, b_lose;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        c = 1;
        over = a_lose = b_lose = false;
        while(!over) {
            if (a >= c) {
                a -= c;
                c++;
            }
            else {
                over = true;
                a_lose = true;
            }
            if (!over) {
                if (b >= c) {
                    b -= c;
                    c++;
                }
                else {
                    over = true;
                    b_lose = true;
                }
            }
        }
        cout << ((a_lose) ? "BOB\n" : "LIMAK\n");
    }
    return 0;
}
