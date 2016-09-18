#include <bits/stdc++.h>
using namespace std;

int main () {
    int A;
    cin >> A;
    vector<int> isComposite(A + 1, 0);
    vector<int> primes, sol;
    int i = 2;
    while (i <= A) {
        if (!isComposite[i]) {
            primes.push_back(i);
            int j = 2 * i;
            while (j <= A) {
                isComposite[j] = 1;
                j += i;
            }
        }
        i++;
    }

    return 0;
}
