#include <bits/stdc++.h>
using namespace std;

class Trie {
	struct node {
		char _data;
		node * _links[26];
		int _children;
		node(char data) : _data(data), _links(), _children(0) {}
	};

	bool _possible;
	vector<string> _blocks;
	node * _roots[26];
	node * _insert(node * n, const string &s, int pos) {
		if (!n) n = new node(s[pos]);
		if (pos + 1 < s.length()) {
			n -> _links[(int)s[pos + 1] - 97] = _insert(n -> _links[(int)s[pos + 1] - 97], s, pos + 1);
			n -> _children++;
		}
		return n;
	}
	void _print(node * n, string s) {
		if (!n) return;
		s += n -> _data;
		if (!n -> _children) _blocks.push_back(s);
		else {
			for (int i = 0; i < 26; i++) _print(n -> _links[i], s);
		}
	}

public:
	Trie() : _roots() { _possible = true; }
	void insert(const string &s) { _roots[(int)s[0] - 97] = _insert(_roots[(int)s[0] - 97], s, 0); }
	void addBlock(string s) { _blocks.push_back(s); }
	void findFilters(Trie * u) {
		// cout << "Finding filters for all blocked websites: \n";
		// for (int i = 0; i < _blocks.size(); i++) cout << _blocks[i] << "\n";

		for (int i = 0; i < _blocks.size() && _possible; i++) {
			// cout << "For " << _blocks[i] << "\n";

			node * n = _roots[(int)_blocks[i][0] - 97];
			string s;
			int pos = 0;
			while(n && pos < _blocks[i].length()) {
				s += _blocks[i][pos];
				n = n -> _links[(int)_blocks[i][pos + 1] - 97];
				pos++;
				// cout << "S became " << s << "\n";
			}
			if (pos == _blocks[i].length()) _possible = false;
			else {
				s += _blocks[i][pos];
				u -> insert(s);
				// cout << "Inserting " << s << " into filters trie\n";
			}
		}
	}
	void print() {
		_blocks.clear();
		for (int i = 0; i < 26; i++) _print(_roots[i], "");
		cout << _blocks.size() << "\n";
		for (int i = 0; i < _blocks.size(); i++) cout << _blocks[i] << "\n";
	}
	bool is_possible() { return _possible; }
};

int main(int argc, char const *argv[])
{

	Trie t, u;
	int n;
	char ch;
	string s;

	cin >> n;
	while (n--) {
		cin >> ch >> s;
		if (ch == '+') t.insert(s);
		else t.addBlock(s);
	}
	t.findFilters(&u);
	if (t.is_possible()) u.print();
	else cout << "-1";
	return 0;
}