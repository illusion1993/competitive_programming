#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	string s;
	bool okay, found;

	cin >> t;
	while(t--) {
		okay = true;
		found = false;

		cin >> n >> s;
		for (int i = 0; i < n; i++) {
			if ((s[i] == 'T' && okay) || (s[i] == 'H' && !okay)) {
				cout << "Invalid\n";
				found = true;
				break;
			}
			else if (s[i] == 'H' && okay) okay = false;
			else if (s[i] == 'T' && !okay) okay = true;
		}
		if (!found) cout << ((okay) ? "Valid\n" : "Invalid\n");
	}
	return 0;
}