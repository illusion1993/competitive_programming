#include<bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));

    cout << "10" << endl;
    for (int i = 0; i < 10; i++) {
        int l = 10;

        cout << l << " " << (rand() % l) + 1 << endl;
        string s;
        while(s.length() < l) {
            int occ = (rand() % l/2) + 1, prev = 0;
            for (int j = 0; j < occ; j++) {
                if (s.length() < l) {
                    s += (prev) ? '0' : '1';
                }
                prev = !prev;
            }
        }
        cout << s << "\n";
    }

    return 0;
}
