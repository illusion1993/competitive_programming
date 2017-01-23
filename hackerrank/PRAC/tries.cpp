#include<bits/stdc++.h>

using namespace std;

struct node {
    char ch;
    bool isTerminal;

    vector<node*> link;
    int indexOfLink[26];

    node() : indexOfLink(){}
};

node head;
/*
void printTrie(node *n, string s) {
    int links = 0;

    if (n -> ch) {
        s = s + n -> ch;
    }

    if (n -> isTerminal) {
        cout << s << endl;
    }

    for (int i = 0; i < 26; i++) {
        if (n -> link[i] != NULL) {
            printTrie(n -> link[i], s);
        }
    }
}
*/

void addString(node *n, string s) {
    if (!s.length()) {
        n -> isTerminal = true;
        return;
    }
    if (!n -> indexOfLink[(int)s[0] - 97]) {
        node *m = new node();
        m -> ch = s[0];
        n -> link.push_back(m);
        n -> indexOfLink[(int)s[0] - 97] = n -> link.size();
    }
    addString(n -> link[n -> indexOfLink[(int)s[0] - 97] - 1], s.substr(1));
}

int countLeaves(node *n, string s) {
    //if (!n) return 0;
    if (s.length()) {
        if (!n -> indexOfLink[(int)s[0] - 97]) return 0;
        return countLeaves(n -> link[n -> indexOfLink[(int)s[0] - 97] - 1], s.substr(1));
    }
    int l = 0;
    for (int i = 0; i < n -> link.size(); i++) {
        l += countLeaves(n->link[i], s);
    }
    if (n -> isTerminal) l++;
    return l;
}

int main() {
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        if (op == "add") {
            addString(&head, contact);
        }
        else {
            cout << countLeaves(&head, contact) << endl;
        }
    }
    //cout << "printing trie strings: " << endl;
    //printTrie(&head, "");
    return 0;
}
