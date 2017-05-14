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
		void insert(const string &s, int pos, vector<int> &ids) {
			for (int i = 0; i < ids.size(); i++) _ids.insert(ids[i]);
			if (pos != s.length() - 1) {
				if (!_links[s[pos + 1] == '1']) _links[s[pos + 1] == '1'] = new node(s[pos + 1] == '1');
				_links[s[pos + 1] == '1'] -> insert(s, pos + 1, ids);
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
	void insert(const string &s, vector<int> &ids) {
		node * n = _roots[s[0] == '1'];
		if (!n) _roots[s[0] == '1'] = new node(s[0] == '1');
		_roots[s[0] == '1'] -> insert(s, 0, ids);
	}
	int getMinXor(const string &k, int id) {
		// cout << "finding min xor of string " << k << " and for id " << id << "\n";
		bool this_bit = (k[0] == '1');
		if (_roots[this_bit] && _roots[this_bit] -> _ids.count(id)) return _roots[this_bit] -> getXor(k, 0, "", id, 0);
		else if (_roots[!this_bit] && _roots[!this_bit] -> _ids.count(id)) return _roots[!this_bit] -> getXor(k, 0, "", id, 0);
		else return 0;
	}
	int getMaxXor(const string &k, int id) {
		// cout << "finding max xor of string " << k << " and for id " << id << "\n";
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

class GPD {
	BinaryTrie * _keyTrie;
	struct node{
		int _id, _key;
		node * parent;
		vector<int> _ids;	// 
		node(int id) : _id(id) {}
		void set_key(int k) { _key = k; }
	};
	unordered_map<int, node*> _nodebook;
	node * _root;
	node * _get_node(int id) {
		if (!id) return NULL;
		if (_nodebook.count(id)) return _nodebook[id];
		node *n = new node(id);
		_nodebook[id] = n;
		return n;
	}

public:
	GPD(int gordon_id, int gordon_key) { add_node(0, gordon_id, gordon_key); _root = _nodebook[gordon_id]; }
	void add_node(int parent_id, int id, int key, BinaryTrie * bt) {
		node * n, * p;
		p = _get_node(parent_id);
		n = _get_node(id);
		n -> set_key(key);
		if (p) {
			n -> _links.push_back(p);
			p -> _links.push_back(n);
		}
	}
	// void make_trie(BinaryTrie * bt) {
	// 	// cout << "Called make_trie\n";
	// 	_root -> ask(-1, bt);
	// }
};

int main(int argc, char const *argv[])
{
	// std::ios::sync_with_stdio(false);
    // cin.tie(0);

	BinaryTrie * bt = new BinaryTrie;
	int N, Q, R, key, u, v, k, t;

	cin >> N >> Q;
	cin >> R >> key;
	GPD g(R, key);

	for (int i = 0; i < N - 1; i++)
	{
	    cin >> u >> v >> k;
	    g.add_node(v, u, k, bt);
	}
	// g.make_trie(bt);

	int last_answer = 0;

	for (int i = 0; i < Q; i++)
	{
	    cin >> t;
	    
	    // find real value of t
	    t ^= last_answer;

	    if (t == 0)
	    {
	        cin >> v >> u >> k;
	        
	        // find real values for u, v, and k
	        u ^= last_answer;
	        v ^= last_answer;
	        k ^= last_answer;
	        vector<int> vec(1, u);
	        bt -> insert(toBinary(k), vec);
	        bt -> add_id(v, u);
	    }
	    else
	    {
	        cin >> v >> k;

	        // find real values for v, and k
	        v ^= last_answer;
	        k ^= last_answer;
	        
	        // compute the requested values
	        // pair<int, int> ans;
	        // ans = bt -> minMaxXor(toBinary(k), v);
	        string s;
	        s = toBinary(k);
	        int min_answer = bt -> getMinXor(s, v);
	        int max_answer = bt -> getMaxXor(s, v);

	        // update last_answer
	        last_answer = min_answer ^ max_answer;  
	        cout << min_answer << " " << max_answer << "\n";
	    }
	}

	return 0;
}