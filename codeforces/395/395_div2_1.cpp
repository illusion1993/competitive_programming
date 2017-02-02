#include<bits/stdc++.h>

using namespace std;

int lcm(int a, int b) {
    if (a % b == 0) return a;

    if (b % a == 0) return b;

    return (a * b) / __gcd(a, b);

}

int main() {
    int n, m, z;
    cin >> n >> m >> z;
    cout << z / lcm(n, m);
}
