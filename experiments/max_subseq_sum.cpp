#include <bits/stdc++.h>

using namespace std;

int main(){

    int a[8] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int s[8];

    s[0] = max(a[0], 0);
    for(int i = 1; i < 8; i++) s[i] = max(s[i - 1], max(s[i - 1] + a[i], a[i]));

    for(int i = 0; i < 8; i++) cout << s[i] << " ";

    return 0;

}
