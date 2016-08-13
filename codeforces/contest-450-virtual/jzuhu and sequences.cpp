#include <bits/stdc++.h>

using namespace std;

int main(){

    int x, y, n;
    cin >> x >> y >> n;

    if(n % 6 == 1) cout << (x + 1000000007) % 1000000007;
    else if(n % 6 == 2) cout << (y + 1000000007) % 1000000007;
    else if(n % 6 == 3) cout << ((y-x) + 1000000007) % 1000000007;
    else if(n % 6 == 4) cout << ((-x) + 1000000007) % 1000000007;
    else if(n % 6 == 5) cout << ((-y) + 1000000007) % 1000000007;
    else if(n % 6 == 0) cout << ((-y+x) + 1000000007) % 1000000007;

    return 0;
}
