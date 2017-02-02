#include<bits/stdc++.h>

using namespace std;

int main() {
    int a[] = {1, 2, 3};
    while(next_permutation(a, a + 3)) {
        for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
