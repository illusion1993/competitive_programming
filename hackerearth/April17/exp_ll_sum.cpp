#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll sumAp(ll a, ll l) {
    ll sum = (2 * a) + (l - a);
    if (sum % 2 == 0) {
        sum /= 2;
        sum *= (l - a + 1);
    }
    else {
        sum *= ((l - a + 1) / 2);
    }
    return sum;
}

int main()
{

    ll a, l;
    do {
        cin >> a >> l;
        cout << sumAp(a, l) << "\n";
    }
    while(a && l);

    return 0;
}
