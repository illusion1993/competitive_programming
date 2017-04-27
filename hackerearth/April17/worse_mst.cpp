#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, k, u, v, w;
class Node;
class Edge;
Node * nodebook[5001];
unordered_set<int> MST;
Node * mst_terminal;

class Node {
	int index_;
	vector<Edge *> edges_;
public:
	Node(int i) : index_(i) {}
	int index() { return index_; }
	void addEdge(Edge * e) { edges_.push_back(e); }
	bool isTerminal() { return (edges_.size() == 1); }
	void tell(Edge * parent);
};

class Edge {
	Node * nodes_[2];
	unordered_set<int> sets_[2];
	int weight_, index_;
public:
	Edge(int a, int b, int w, int i) : weight_(w) , index_(i) {
		nodes_[0] = nodebook[a];
		nodes_[1] = nodebook[b];
		nodes_[0] -> addEdge(this);
		nodes_[1] -> addEdge(this);
	}
	int index() { return index_; }
	int weight() { return weight_; }
	int v1() { return nodes_[0] -> index(); }
	int v2() { return nodes_[1] -> index(); }
	void addSet(unordered_set<int> t, Node * parent);
	unordered_set<int> getOtherSet(Node * parent);
	Node * getOtherNode(Node * parent);
};

// Class Node-----------------------------------------
void Node::tell(Edge * parent) {
	for (int i = 0; i < edges_.size(); i++) {
		if (edges_[i] != parent && MST.count(edges_[i] -> index())) {
			if (parent) edges_[i] -> addSet(parent -> getOtherSet(this), this);
			else {
				unordered_set<int> x;
				edges_[i] -> addSet(x, this);
			}
			edges_[i] -> getOtherNode(this) -> tell(edges_[i]);
		}
	}
}

// Class Edge-----------------------------------------
void Edge::addSet(unordered_set<int> t, Node * parent) {
	t.insert(parent -> index());
	if (parent == nodes_[0]) {
		sets_[0] = t;
		for (int i = 1; i <= n; i++) if (sets_[0].count(i) == 0) sets_[1].insert(i);
	}
	else {
		sets_[1] = t;
		for (int i = 1; i <= n; i++) if (sets_[1].count(i) == 0) sets_[0].insert(i);
	}
	
	// cout << "For edge " << nodes_[0] -> index() << " - " << nodes_[1] -> index() << ", sets are found:\n";
	// cout << "Set 0: ";
	// for (int i = 1; i <= n; i++) {
	// 	if (sets_[0].count(i)) cout << i << " ";
	// }
	// cout << "\n";
	// cout << "Set 1: ";
	// for (int i = 1; i <= n; i++) {
	// 	if (sets_[1].count(i)) cout << i << " ";
	// }
	// cout << "\n";
}
unordered_set<int> Edge::getOtherSet(Node * parent) {
	if (parent == nodes_[0]) return sets_[1];
	else return sets_[0];
}
Node * Edge::getOtherNode(Node * parent) {
	if (parent == nodes_[0]) return nodes_[1];
	else return nodes_[0];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<pair<int, Edge * > > e;
	unordered_map<int, int> mst_set;
	int mst_set_count = 0;

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) nodebook[i] = new Node(i);
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		Edge * ed = new Edge(u, v, w, i + 1);

		e.push_back({w, ed});
	}
	sort(e.begin(), e.end());
	for (int i = 0; i < e.size(); i++) {
		if (mst_set.count(e[i].second -> v1()) != 0 && mst_set.count(e[i].second -> v2()) == 0) {
			mst_set[e[i].second -> v2()] = mst_set[e[i].second -> v1()];
			MST.insert(e[i].second -> index());
			// cout << "Adding " << e[i].second -> v2() << " in set of " << e[i].second -> v1() << "\n";
		}
		else if (mst_set.count(e[i].second -> v1()) == 0 && mst_set.count(e[i].second -> v2()) != 0) {
			// cout << "Adding " << e[i].second -> v1() << " in set of " << e[i].second -> v2() << "\n";
			mst_set[e[i].second -> v1()] = mst_set[e[i].second -> v2()];
			MST.insert(e[i].second -> index());
		}
		else if (mst_set.count(e[i].second -> v1()) == 0 && mst_set.count(e[i].second -> v2()) == 0) {
			mst_set_count++;
			mst_set[e[i].second -> v1()] = mst_set[e[i].second -> v2()] = mst_set_count;
			MST.insert(e[i].second -> index());
			// cout << "Adding " << e[i].second -> v1() << " and " << e[i].second -> v2() << "in new set\n";
		}
	}
	



	for (int i = 1; i <= n; i++) {
		if (nodebook[i] -> isTerminal()) {
			mst_terminal = nodebook[i];
			break;
		}
	}
	mst_terminal -> tell(NULL);
	cout << m << "\n";
	for (int i = 0; i < m; i++) cout << i + 1 << " ";

    return 0;
}

/*
MY OWN SAMPLE TESTCASE
8 11 2
1 2 2
2 5 3
1 4 3
2 4 1
5 3 4
5 6 4
4 3 1
3 6 3
4 7 2
4 8 3
8 6 4
*/