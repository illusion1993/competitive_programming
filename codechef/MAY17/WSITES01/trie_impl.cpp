#include <bits/stdc++.h>
using namespace std;

class Trie {

	struct node {
		char _data;
		node * _links[26];
		bool _positive, _negative;

		node(char data) : _data(data) {}
		void traversing(bool is_positive) {
			if (is_positive) _positive = true;
			else _negative = true;
		}
	};

	node * _roots[26];
	node * _insert(node * n, const string &s, int pos, bool is_positive) {
		if (!n) n = new node(s[pos]);
		n -> traversing(is_positive);
		if (pos + 1 < s.length()) { 
			n -> _links[(int)s[pos + 1] - 97] = _insert(n -> _links[(int)s[pos + 1] - 97], s, pos + 1, is_positive);
		}
		return n;
	}
	void _print(node * n, string s) {
		int c = 0;
		s += n -> _data;
		for (int i = 0; i < 26; i++) {
			if (n -> _links[i]) {
				c++;
				_print(n -> _links[i], s);
			}
		}
		if (!c) cout << s << "\n";
	}

public:
	Trie() {
		for (int i = 0; i < 26; i++) _roots[i] = NULL;
	}
	void insert(const string &s, bool is_positive) {
		_roots[(int)s[0] - 97] = _insert(_roots[(int)s[0] - 97], s, 0, is_positive);
	}
	void printAll() {
		for (int i = 0; i < 26; i++) if (_roots[i]) _print(_roots[i], "");
	}

};

int main(int argc, char const *argv[])
{

	Trie t;
	string s;
	for (int i = 0; i < 5; i++)	{
		cin >> s;
		t.insert(s, 0);
	}
	t.printAll();
	return 0;
}