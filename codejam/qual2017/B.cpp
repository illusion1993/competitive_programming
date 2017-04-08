#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	// std::ios::sync_with_stdio(false);
    // cin.tie(0);

    // ofstream cout ("B-large.out");
    // ifstream cin ("B-large.in");

    int t;
    string s;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
    	cin >> s;
    	int pos = 1;
    	while(s[pos] >= s[pos - 1] && pos < s.length()) pos++;
    	if (pos != s.length()) {
    		s[pos - 1]--;
    		pos--;
    		while(pos > 0 && s[pos] < s[pos - 1]) {
    			s[pos - 1]--;
    			pos--;
    		}
    		for (int i = pos + 1; i < s.length(); i++) s[i] = '9';
    	}
    	pos = 0;
    	while(s[pos] == '0') {
    		pos++;
    	}

    	cout << "Case #" << tc << ": ";
    	for (int i = pos; i < s.length(); i++) cout << s[i];
    	cout << "\n";
    }

	return 0;
}