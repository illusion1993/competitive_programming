#include<bits/stdc++.h>
using namespace std;

int t;
string s;

long long solve() {
    long long ones, dots, moves;
    ones = dots = moves = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') dots++;
        else {
            if (dots) moves += ones + (ones * dots);
            ones++;
            dots = 0;
        }
    }
    if (dots) moves += ones + (ones * dots);
    return moves;
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> s;
        cout << solve() << "\n";
    }

    return 0;
}
