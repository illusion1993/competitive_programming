#include<bits/stdc++.h>
using namespace std;

int a[10];

bool isHappy(int n) {
    int tmp, occ[10];
    bool happy = true;
    memset(occ, 0, sizeof(occ));
    tmp = n;
    while(tmp) {
        occ[tmp % 10]++;
        tmp /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (a[i] == occ[i]) happy = false;
    }
    return happy;
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int t, l, r, happy;
    cin >> t;
    while(t--) {
        happy = 0;
        cin >> l >> r;
        for (int i = 0; i < 10; i++) cin >> a[i];
        for (int i = l; i <= r; i++) {
            if (isHappy(i)) happy++;
        }
        cout << happy << "\n";
    }

    return 0;
}
