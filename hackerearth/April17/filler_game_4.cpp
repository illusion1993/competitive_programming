#include<bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<string, bool> is_winning_state;
string board;

bool isWinning() {
	if (is_winning_state.count(board)) return is_winning_state[board];
	
	bool winning = false;
	for (int i = 0; i < board.length(); i++) {
		if (board[i] == '0') {
			bool okay = false;
			if (i/m != 0 && board[i - m] == '0') okay = true;
			else if (i/m != n-1 && board[i + m] == '0') okay = true;
			else if (i%m != 0 && board[i - 1] == '0') okay = true;
			else if (i%m != m-1 && board[i + 1] == '0') okay = true;
			if (okay) {
				board[i] = '1';
				if (!isWinning()) winning = true;
				board[i] = '0';
			}
		}
	}
	is_winning_state[board] = winning;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q;
	string s, state;
	cin >> n >> m >> q;

	board = "";
	for (int i = 0; i < m*n; i++) board += '0';
	isWinning();
	while(q--) {
		state = "";
		for (int i = 0; i < n; i++) {
			cin >> s;
			state += s;
		}
		if (is_winning_state.count(state)) cout << !is_winning_state[state] << "\n";
		else cout << "1\n";
	}

    return 0;
}