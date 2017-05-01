#include<bits/stdc++.h>
using namespace std;


class Node {
	int data_;
	struct Node *left_, *right_;
public:
	Node() : left_(NULL), right_(NULL) {}
	Node(int data) : data_(data), left_(NULL), right_(NULL) {}
	int data() { return data_; }
	int data(int data) { data_ = data; return data_; }
	Node * left() { return left_; }
	Node * right() { return right_; }
	Node * left(Node * left) { left_ = left; return left_; }
	Node * right(Node * right) { right_ = right; return right_; }
};

class BST {
	Node * root_;
	int size_;
	vector<int> traversal_;
	
	Node * insert_(Node * node, int data) {
		if(node == NULL) return new Node(data);
		if(node -> data() >= data) node -> left(insert_(node -> left(), data));
		else node -> right(insert_(node -> right(), data));	
		return node;
	}
	int height_(Node * node) {
		if(node == NULL) return 0;
		int lh = 0, rh = 0;
		if(node -> left()) lh = height_(node -> left());
		if(node -> right()) rh = height_(node -> right());
		return max(lh, rh) + 1;
	}
	void inorder_(Node * node, bool print = false) {
		if (node) {
			inorder_(node -> left(), print);
			if (print) cout << node -> data() << " ";
			traversal_.push_back(node -> data());
			inorder_(node -> right(), print);
		}
	}
	void preorder_(Node * node, bool print = false) {
		if (node) {
			if (print) cout << node -> data() << " ";
			traversal_.push_back(node -> data());
			preorder_(node -> left(), print);
			preorder_(node -> right(), print);
		}
	}
	void postorder_(Node * node, bool print = false) {
		if (node) {
			postorder_(node -> left(), print);
			postorder_(node -> right(), print);
			if (print) cout << node -> data() << " ";
			traversal_.push_back(node -> data());
		}
	}
public:
	BST() : root_(NULL), size_(0) {}
	BST(int data) : root_(new Node(data)), size_(1) {}
	void insert(int data) {
		if (!root_) root_ = insert_(root_, data);
		else insert_(root_, data);
		size_++;
	}
	int height() { return height_(root_); }
	int size() { return size_; }
	vector<int> inorder(bool print = false) {
		traversal_.clear();
		inorder_(root_, print);
		return traversal_;
	}
	vector<int> preorder(bool print = false) {
		traversal_.clear();
		preorder_(root_, print);
		return traversal_;
	}
	vector<int> postorder(bool print = false) {
		traversal_.clear();
		postorder_(root_, print);
		return traversal_;
	}
};

int main()
{
	int n, tmp;
	BST b1;
	BST b2(12);		// With root 12, only for example


	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		b1.insert(tmp);
	}


	cout << "Size: " << b1.size() << "\n";
	cout << "Height: " << b1.height() << "\n";
	cout << "Inorder: ";
	b1.inorder(true);
	cout << "\nPreorder: ";
	b1.preorder(true);
	cout << "\nPostorder: ";
	b1.postorder(true);
	cout << endl;

	return 0;
}