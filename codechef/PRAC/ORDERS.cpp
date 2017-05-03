#include<bits/stdc++.h>
using namespace std;

struct node {
	int index, shifts, rank;
	node * prev, * next;
};

node * head, * tail;
int n, ans[200000];

void init() {
	head = tail = NULL;
}

void insert(int index_, int shifts_) {
	node * n = new node();
	n -> index = index_;
	n -> shifts = shifts_;

	if (!tail) {
		head = tail = n;
		n -> prev = n -> next = NULL;
	}
	else {
		tail -> next = n;
		n -> prev = tail;
		n -> next = NULL;
		tail = n;
	}
}

void shiftLeft(node * n) {
	if (!n) return;
	node * nextCall = n -> next;
	// iterate s times left
	node * iter = n;
	while(n -> shifts) {
		n -> shifts--;
		iter = iter -> prev;
	}
	// insert at this pos
	if (iter != n) {
		// Pluck out
		if (n -> prev) n -> prev -> next = n -> next;
		if (n -> next) n -> next -> prev = n -> prev;

		n -> prev = iter -> prev;
		if (n -> prev) n -> prev -> next = n;
		n -> next = iter;
		iter -> prev = n;
		if (iter == head) head = n;
	}
	shiftLeft(nextCall);
}

void findRanks() {
	int rank = 1;
	node * iter = head;

	while(iter) {
		ans[iter -> index] = rank;
		rank++;
		iter = iter -> next;
	}
}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(false);
    cin.tie(0);

	int t, tmp;
	cin >> t;
	while(t--) {
		init();
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			insert(i, tmp);
		}
		shiftLeft(head);
		findRanks();
		for (int i = 0; i < n; i++) cout << ans[i] << " ";
		cout << "\n";
	}

	return 0;
}
