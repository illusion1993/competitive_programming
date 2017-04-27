#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, q, maxcode;
vector<string> board, query;
unordered_map<int, bool> is_winning_position;

bool isEmptyCell(int r, int c) {
	// cout << "called isEmptyCell at " << r << ", " << c << ": ";
	if (r < 0 || r >= n || c < 0 || c >= m) {
		// cout << "No\n";
		return 0;
	}
	// cout << ((board[r][c] == '0') ? "Yes\n" : "No\n");
	return (board[r][c] == '0');
}

int encodeBoard(vector<string> v) {
	int power = 0, code = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			code += (v[i][j] == '1') ? pow(2, power) : 0;
			power++;
		}
	}
	return code;
}

bool isWinningPosition() {
	int code = encodeBoard(board);
	// cout << "came at code " << code << "\n";
	if (is_winning_position.count(code)) return is_winning_position[code];

	bool winning = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '0' && (isEmptyCell(i - 1, j) || isEmptyCell(i + 1, j) || isEmptyCell(i, j - 1) || isEmptyCell(i, j + 1))) {
				board[i][j] = '1';
				winning = winning || !isWinningPosition();
				board[i][j] = '0';
			}
			else {
				// cout << "cant place at " << i << ", " << j << "\n";
			}
		}
	}
	is_winning_position[code] = winning;
	// cout << code << ": " << winning << "\n";
	return winning;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) s += '0';
	for (int i = 0; i < n; i++) board.push_back(s);

	isWinningPosition();
	
	int code;
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s;
			query.push_back(s);
		}
		code = encodeBoard(query);
		cout << (is_winning_position.count(code) ? is_winning_position[code] : '0');
		cout << "\n";
	}

    return 0;
}