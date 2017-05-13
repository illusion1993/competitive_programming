#include<bits/stdc++.h>
using namespace std;

class GothamPD{
	struct node {
		int _id, _key;
		node * _parent;
		vector<node*> _links;
		node(int id) : _id(id), _parent(NULL), _links() {}
		void setParent(node * p) {
			// if (p) cout << "Setting parent for node " << _id << " to be " << p -> _id << "\n";
			// else cout << "Setting parent for node " << _id << " to be NULL\n";
			_parent = p;
			for (int i = 0; i < _links.size(); i++) if(_links[i] != p) _links[i] -> setParent(this);
		}
		pair<int, int> minMaxXor(int k) {
			if (!_parent) return {_key^k, _key^k};
			pair<int, int> ans;
			ans = _parent -> minMaxXor(k);
			ans.first = min(ans.first, _key^k);
			ans.second = max(ans.second, _key^k);
			return ans;
		};
	};
	unordered_map<int, node*> _nodebook;
	int _size;
	node * _root;
	node * _getNode(int id) {
		if (_nodebook.count(id)) return _nodebook[id];
		node * n = new node(id);
		_nodebook[id] = n;
		return n;
	}
	node * _createNode(int id, int link_id, int key) {
		// cout << "Creating node:\nId: " << id << "\nLink Id: " << link_id << "\nKey: " << key << "\n";
		node * n, * link;
		n = _getNode(id);
		n -> _key = key;
		
		if (link_id) {
			link = _getNode(link_id);
			n -> _links.push_back(link);
			link -> _links.push_back(n);
		}
		// cout << "Links: " << n -> _links.size() << "\n";
		return n;
	}
public:
	GothamPD(int size, int gordon_id, int gordon_key) : _size(size) { 
		_root = _createNode(gordon_id, 0, gordon_key);
	}
	void insertNewNode(int link_id, int id, int key, bool set_parent = false) {
		node * parent, * n;
		n = _createNode(id, link_id, key);
		if (set_parent) {
			parent = _getNode(link_id);
			n -> setParent(parent);
		}
	}
	void setParents() { _root -> setParent(NULL); }
	pair<int, int> findMinMaxXor(int v, int k) {
		node * n;
		n = _getNode(v);
		return n -> minMaxXor(k);
	}
};

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
    cin.tie(0);
	
	int N, Q, R, key, u, v, k, t;

	cin >> N >> Q;
	cin >> R >> key;
	GothamPD g(N, R, key);

	for (int i = 0; i < N - 1; i++)
	{
	    cin >> u >> v >> k;
	    g.insertNewNode(v, u, k);
	}
	g.setParents();

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
	        g.insertNewNode(v, u, k, true);
	    }
	    else
	    {
	        cin >> v >> k;

	        // find real values for v, and k
	        v ^= last_answer;
	        k ^= last_answer;
	        
	        // compute the requested values
	        pair<int, int> ans;
	        ans = g.findMinMaxXor(v, k);
	        int min_answer = ans.first;
	        int max_answer = ans.second;

	        // update last_answer
	        last_answer = min_answer ^ max_answer;  
	        cout << min_answer << " " << max_answer << "\n";
	    }
	}
	return 0;
}