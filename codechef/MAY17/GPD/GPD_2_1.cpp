#include<bits/stdc++.h>
using namespace std;

string toBinary(int x) {
	string s, s_n;
	s = s_n = "";
	for (int i = 0; i < 31; i++) {
		s = (x % 2) ? s + '1' : s + '0';
		x /= 2;
	}
	for (int i = 0; i < s.length(); i++) s_n += s[s.length() - 1 - i];
	return s_n;
}

int toDecimal(string s) {
	int val = 0, m = 1;
	for (int i = 0; i < s.length(); i++) {
		val += m * (s[s.length() - 1 - i] == '1');
		m *= 2;
	}
	return val;
}

class BinaryTrie {
	struct node {
		bool _val, _all;
		node * _links[2];
		unordered_set<int> _ids;
		node(bool val) : _val(val), _links() {}
		void insert(const string &s, int pos, int id) {
			_ids.insert(id);
			if (pos != s.length() - 1) {
				if (!_links[s[pos + 1] == '1']) _links[s[pos + 1] == '1'] = new node(s[pos + 1] == '1');
				_links[s[pos + 1] == '1'] -> insert(s, pos + 1, id);
			}
		}
		void add_id(int parent_id, int new_id) {
			_ids.insert(new_id);
			if (_links[0] && _links[0] -> _ids.count(parent_id)) _links[0] -> add_id(parent_id, new_id);
			if (_links[1] && _links[1] -> _ids.count(parent_id)) _links[1] -> add_id(parent_id, new_id);
		}
		int getXor(const string &k, int pos, string xorSoFar, int id, bool max) {
			bool this_bit = (k[pos] == '1');
			xorSoFar = (this_bit^_val) ? xorSoFar + '1' : xorSoFar + '0';
			if (pos < k.length() - 1) this_bit = (k[pos + 1] == '1');

			if (!max) {
				if (_links[this_bit] && _links[this_bit] -> _ids.count(id)) return _links[this_bit] -> getXor(k, pos + 1, xorSoFar, id, max);
				else if (_links[!this_bit] && _links[!this_bit] -> _ids.count(id)) return _links[!this_bit] -> getXor(k, pos + 1, xorSoFar, id, max);
				else return toDecimal(xorSoFar);
			}
			else {
				if (_links[!this_bit] && _links[!this_bit] -> _ids.count(id)) return _links[!this_bit] -> getXor(k, pos + 1, xorSoFar, id, max);
				else if (_links[this_bit] && _links[this_bit] -> _ids.count(id)) return _links[this_bit] -> getXor(k, pos + 1, xorSoFar, id, max);
				else return toDecimal(xorSoFar);
			}
		}
	};
	node * _roots[2];

public:
	BinaryTrie() : _roots() {}
	void insert(const string &s, int id) {
		node * n = _roots[s[0] == '1'];
		if (!n) _roots[s[0] == '1'] = new node(s[0] == '1');
		_roots[s[0] == '1'] -> insert(s, 0, id);
	}
	int getMinXor(const string &k, int id) {
		bool this_bit = (k[0] == '1');
		if (_roots[this_bit] && _roots[this_bit] -> _ids.count(id)) return _roots[this_bit] -> getXor(k, 0, "", id, 0);
		else if (_roots[!this_bit] && _roots[!this_bit] -> _ids.count(id)) return _roots[!this_bit] -> getXor(k, 0, "", id, 0);
		else return 0;
	}
	int getMaxXor(const string &k, int id) {
		bool this_bit = (k[0] == '1');
		if (_roots[!this_bit] && _roots[!this_bit] -> _ids.count(id)) return _roots[!this_bit] -> getXor(k, 0, "", id, 1);
		else if (_roots[this_bit] && _roots[this_bit] -> _ids.count(id)) return _roots[this_bit] -> getXor(k, 0, "", id, 1);
		else return 0;
	}
	void add_id(int parent_id, int new_id) {
		if (_roots[0] && _roots[0] -> _ids.count(parent_id)) _roots[0] -> add_id(parent_id, new_id);
		if (_roots[1] && _roots[1] -> _ids.count(parent_id)) _roots[1] -> add_id(parent_id, new_id);
	}
};

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
    cin.tie(0);

	int N, Q, R, key, u, v, k, t;

	cin >> N >> Q;
	cin >> R >> key;
	BinaryTrie * bt = new BinaryTrie();

	for (int i = 0; i < N - 1; i++)
	{
	    cin >> u >> v >> k;
	    bt -> insert(toBinary(k), u);
	    bt -> add_id(v, u);
	}

	int last_answer = 0;

	for (int i = 0; i < Q; i++)
	{
	    cin >> t;
	    t ^= last_answer;

	    if (t == 0)
	    {
	        cin >> v >> u >> k;
	        u ^= last_answer;
	        v ^= last_answer;
	        k ^= last_answer;
	        bt -> insert(toBinary(k), u);
	        bt -> add_id(v, u);
	    }
	    else
	    {
	        cin >> v >> k;
	        v ^= last_answer;
	        k ^= last_answer;
	        string s;
	        s = toBinary(k);
	        int min_answer = min(bt -> getMinXor(s, v), k^key);
	        int max_answer = max(bt -> getMaxXor(s, v), k^key);
	        last_answer = min_answer ^ max_answer;  
	        cout << min_answer << " " << max_answer << "\n";
	    }
	}

	return 0;
}