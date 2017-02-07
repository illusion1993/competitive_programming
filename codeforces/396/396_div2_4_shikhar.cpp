#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define MAX 100001
#define MOD 1000000007
using namespace std;
const string def = "-1";
int n, m, q;
string dict[MAX];
map<string, string> mp, opp;
map<string, int> sz;
string find(string p)   {
    string root = mp[p];
    while (root != mp[root])
        root = mp[root];
    while (p != root) {
        string newp = mp[p];
        mp[p] = root;
        p = newp;
    }
    return root;
}
void merge(string x, string y)  {
    if (x.length() == 0 || y.length() == 0 ||  x == def || y == def) return;
    string i = find(x);
    string j = find(y);
    if (i == j) return;
    if   (sz[i] < sz[j]) { mp[i] = j; sz[j] += sz[i]; }
    else                 { mp[j] = i; sz[i] += sz[j]; }
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1;i <= n; ++i) cin >> dict[i], opp[dict[i]] = "-1", mp[dict[i]] = dict[i], sz[dict[i]] = 1;
    string a, b;
    int t;
    for (int j = 1;j <= m; ++j) {
        cin >> t >> a >> b;
        if (t == 1) {
            if (mp[a] == mp[opp[mp[b]]]) {
                cout << "NO\n";
            } else {
                merge(a, b);
                merge(mp[opp[a]], mp[opp[b]]);
                cout << "YES\n";
            }
        } else {
            if (mp[a] == mp[b]) {
                cout << "NO\n";
            } else {
                merge(opp[mp[b]], mp[a]);
                merge(opp[mp[a]], mp[b]);
                merge(opp[mp[a]], opp[mp[b]]);
                opp[mp[a]] = mp[b];
                opp[mp[b]] = mp[a];
                cout << "YES\n";
            }
        }
    }
    while(q--) {
        cin >> a >> b;
        if (mp[a] == mp[b]) cout << "1\n";
        else if(mp[a] == opp[mp[b]] || opp[mp[a]] == mp[b]) cout << "2\n";
        else cout << "3\n";
    }
    return 0;
}
