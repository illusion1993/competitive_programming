#include<bits/stdc++.h>
using namespace std;
#define ll long long

unordered_map<string, bool> is_winning_pos;
int n, m, q;

bool canMoveHere(string s, int pos) {
	if (s[pos] == '1') return false;
	bool move = false;
	
	if (pos - m >= 0 && s[pos - m] == '0') move = true;
	else if (pos + m < n*m && s[pos + m] == '0') move = true;
	else if (pos % m != 0 && s[pos - 1] == '0') move = true;
	else if (pos % m != m - 1 && s[pos + 1] == '0') move = true;
	return move;
}

bool isWinningPos(string s) {
	// cout << "called for string " << s << endl;
	if (is_winning_pos.count(s)) return is_winning_pos[s];

	bool winning = false;
	for (int i = 0; i < s.length() && !winning; i++) {
		if (canMoveHere(s, i)) {
			string s_n = s;
			s_n[i] = '1';
			if (!isWinningPos(s_n)) {
				winning = true;
				cout << "Because " << s_n << " is losing position to give,\n" << s << " is winning position.\n";
			}
		}
	}
	is_winning_pos[s] = winning;
	if (winning) cout << s << " is winning pos\n\n";
	else cout << s << " is losing pos\n\n";
	return winning;
}

void enumerate() {
	string s = "";
	for (int i = 0; i < n * m; i++) s += '0';
	isWinningPos(s);
}

int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	cin >> n >> m >> q;
	enumerate();
	cout << "Total " << is_winning_pos.size() << " board positions\n";

	string s1 = "", s2;
	while(q--) {
		for (int i = 0; i < n; i++) {
			cin >> s2;
			s1 += s2;
		}
		cout << isWinningPos(s1) << "\n";
	}

    return 0;
}