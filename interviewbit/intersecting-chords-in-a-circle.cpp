#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int chordCnt(int A){
        int c[A + 1];
        c[0] = 1;
        if (A) c[1] = 1;
        cout << "1: 1\n";
        for (int i = 2; i <= A; i++) {
            c[i] = 0;
            for (int j = 0; j < i; j++) {
                long long tmp = ((long long)c[j] * (long long)c[i - 1 - j]) % 1000000007;
                c[i] = (c[i] + tmp) % 1000000007;
            }
            cout << i << ": " << c[i] << "\n";
        }
        return c[A];
    }
};

int main(int argc, char const *argv[])
{

    // Create Input
    int a;
    cin >> a;

    // Create solution object
    Solution s;

    // create output container
    int ans;

    // call solution function
    ans = s.chordCnt(a);

    // output answer
    //cout << ans;

    return 0;
}    