#include<bits/stdc++.h>
using namespace std;

int n, k, p;
vector<bool> a;

int calc() {
    int ans = 0;
    for (int i = 0; i + k <= n; i++) {
        int count = 0;
        for (int j = 0; j < k; j++) count += a[i + j];
        ans = max(ans, count);
    }
    return ans;
}

void rotate() {
    // cout << "B: ";
    // for (int i = 0; i < n; i++) cout << a[i] << " ";
    // cout << "\n";

    int l = a.back();
    a.pop_back();
    a.insert(a.begin(), l);

    // cout << "A: ";
    // for (int i = 0; i < n; i++) cout << a[i] << " ";
    // cout << "\n";
}

void process(char ch) {
    if (ch == '!') rotate();
    else cout << calc() << "\n";
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int f, t;
    string s;
    cin >> n >> k >> p;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> t;
        a[i] = t;
    }
    cin >> s;
    for (int i = 0; i < p; i++) {
        process(s[i]);
    }
}