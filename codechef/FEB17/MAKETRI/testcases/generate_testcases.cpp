#include<bits/stdc++.h>
using namespace std;

long long large_rand(long long range) {
    return rand() % range + 1;
}

long long rand_l(long long range) {
    return rand() % (range / 4);
}

long long rand_r(long long range) {
    return range - (rand() % (range / 5));
}

string to_string(int n, int id) {

    string s1 = "";
    string s2 = "";

    while(n) {
        s1 = (char)((n % 10) + 48) + s1;
        n /= 10;
    }

    s1 += '_';

    while(id) {
        s2 = (char)((id % 10) + 48) + s2;
        id /= 10;
    }

    return s1 + s2;

}

int main() {
    int n, nmax, test_id = 0;
    long long l, r, range;
    cin >> nmax;

    for (n = 10; n <= nmax; n *= 5) {
        range = (long long)n * (long long)n;

        for (int i = 0; i < 5; i++) {
            string filename = "tests/test" + to_string(n, i + 1) + ".txt";
            freopen(filename.c_str(),"w",stdout);

            cout << n << " " << rand_l(range) << " " << rand_r(range) << endl;
            for (int j = 0; j < n; j++) {
                cout << large_rand(range) << endl;
            }
            test_id++;
            //cout << endl << "--------------------------------------------------------------------------------------------------------------" << endl << endl;
        }
    }
}
