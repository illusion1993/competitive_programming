#include<bits/stdc++.h>
using namespace std;
int n, q, ans;
int a[50001];

void q1(int pos, int val) {
    a[pos] = val;
}

int q2(int L, int R, int I, int J) {
    int l, r, i, j;
    l = 1 + ((ans ^ L) % n);
    r = 1 + ((ans ^ R) % n);
    if(l > r) {
        int tmp = r;
        r = l;
        l = tmp;
    }
    i = 1 + ((I ^ ans) % (r - l + 1));
    j = 1 + ((J ^ ans) % (r - l + 1));
    if(i > j) {
        int tmp = j;
        j = i;
        i = tmp;
    }
    // cout << "l, r, i, j are: " << l << ", " << r << ", " << i << ", " << j << "\n";

    vector<int> b;
    b.push_back(-1);
    int X;
    for (int p = l; p <= r; p++) b.push_back(a[p]);
    sort(b.begin(), b.end());
    X = b[i];
    // cout << "init X = " << X << endl;
    for (int p = i + 1; p <= j; p++) {
        X = X ^ b[p];
        // cout << "xor with " << b[p] << ", X become " << X << endl;
    }
    ans = X;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ans = 0;
    int Q, L, R, I, J;

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while(q--) {
        cin >> Q;
        if (Q - 1) {
            cin >> L >> R >> I >> J;
            cout << q2(L, R, I, J) << "\n";
        }
        else {
            cin >> L >> R;
            q1(L, R);
        }
    }

    return 0;
}
