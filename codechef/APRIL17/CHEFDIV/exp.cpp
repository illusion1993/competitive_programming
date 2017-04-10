#include<bits/stdc++.h>
using namespace std;

#define PRINTVEC(x, d) for (int i = 0; i < x.size(); i++) cout << x[i] << d;
#define NL cout << "\n";

vector<int> factors(int a) {
    vector<int> fac;
    stack<int> s;

    for (int i = 1; i <= sqrt(a); i++) {
        if (a % i == 0) {
            if (i != a) fac.push_back(i);
            if (i != 1 && i != sqrt(a)) s.push(a / i);
        }
    }

    while(s.size()) {
        fac.push_back(s.top());
        s.pop();
    }

    return fac;
}

int main(int argc, char const *argv[])
{
    // std::ios::sync_with_stdio(false);
    // cin.tie(0);

    vector<int> v;
    int i;
    do {
        cin >> i;
        if (i) {
            v = factors(i);
            cout << i << ": \t";
            PRINTVEC(v, " ")
            cout << "(" << v.size() << ")";
            NL
        }
    }
    while(i);

    // map<int, int> m;
    // m[10] = 100;
    // m[9] = 81;
    // m[2] = 4;
    // m[3] = 9;

    // cout << m.begin() -> first << " : " << m.begin() -> second << endl;
    // cout << m.rbegin() -> first << " : " << m.rbegin() -> second << endl;


    return 0;
}
