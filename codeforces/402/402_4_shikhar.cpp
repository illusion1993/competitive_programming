#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define MOD 1000000007
#define MAX 200001

string t, p;
int a[MAX];
bool done[MAX];
bool isSubsequence(string str1, string str2)
{
    int m = str1.length();
    int n = str2.length(), j = 0;
    for (int i=0; i<n&&j<m; i++)
        if (str1[j] == str2[i])
            j++;
    return (j==m);
}
bool pos(int lim) {
    int l = t.length();
    memset(done, false, sizeof done);
    for (int i = 0;i < lim; ++i) {
        done[a[i] - 1] = true;
    }
    string s = "";
    for (int i = 0;i < l; ++i) if (!done[i]) s += t[i];
    return isSubsequence(p, s);
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> t >> p;
    int l = t.length();
    for (int i = 0;i < l; ++i) cin >> a[i];
    int low = 0, high = l;
    while (low < high) {
        int mid = (low + high) / 2;
        bool po = pos(mid);
        if (po && !pos(mid + 1)) {
            cout << mid << "\n";
            return 0;
        }
        if (po) low = mid + 1;
        else high = mid;
    }
    cout << low << "\n";
    return 0;
}
