#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	map<char, bool> mem;
	string s;
	int n;

	cin >> s;
	for (int i = 0; i < s.length(); i++) mem[s[i]] = true;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		bool reads = true;
		for (int j = 0; j < s.length(); j++) {
			if (mem.count(s[j]) == 0) {
				reads = false;
			}
		}
		cout << ((reads) ? "Yes\n" : "No\n");
	}
}