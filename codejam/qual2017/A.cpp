#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
    cin.tie(0);

    ofstream cout ("A-large.out");
    ifstream cin ("A-large.in");

    int t, k, ans;
    string s;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
    	ans = 0;
    	cin >> s >> k;
    	for (int i = 0; i <= s.length() - k; i++) {
    		if (s[i] == '-') {
    			ans++;
    			for (int j = i; j < i + k; j++) s[j] = (s[j] == '-') ? '+' : '-';
    		}
    	}
    	bool poss = true;
    	for (int i = s.length() - k + 1; i < s.length(); i++) if (s[i] == '-') poss = false;
		cout << "Case #" << tc << ": ";
		if (poss) cout << ans << "\n";
		else cout << "IMPOSSIBLE\n";
    }

	return 0;
}