#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node * prev;
    node * next;
};


node * head;
node * tail;
int t, n, k, inversions_made;


void break_node(node * n) {
    if (n -> val > 1) {
        inversions_made++;
        node * l = new node();
        node * m = new node();
        node * r = new node();

        l -> val = ceil(((float)(n -> val) - 1.00) / 2.00);
        m -> val = 1;
        r -> val = n -> val - l -> val - 1;

        if (n -> prev) n -> prev -> next = l;
        else head = l;
        l -> prev = n -> prev;

        l -> next = m;
        m -> prev = l;

        if (r -> val) {
            m -> next = r;
            r -> prev = m;
            r -> next = n -> next;
            if (n -> next) r -> next -> prev = r;
            else tail = r;
        }

        else {
            m -> next = n -> next;
            if (n -> next) m -> next -> prev = m;
            else tail = m;
        }
    }
}

int largest_node(node * root, bool break_node_also) {
    int lar_val = INT_MIN;
    node * lar_node = NULL;
    while(root) {
        if (root -> val >= lar_val) {
            lar_val = root -> val;
            lar_node = root;
            if (root -> prev && root -> prev -> val == 1 && root -> next && root -> next -> val == 1) lar_node = NULL;
        }
        root = root -> next;
    }
    if (lar_node && break_node_also) break_node(lar_node);
    if (lar_val == 1) inversions_made = k;
    return lar_val;
}


void traverse(node * n) {
    cout << "Linked list is: \n";
    while(n) {
        cout << n -> val << " ";
        n = n -> next;
    }
    cout << "\n";
}

int main() {
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);

    int occ;
    string sch;

    cin >> t;
    while(t--) {
        head = NULL;
        tail = NULL;
        inversions_made = 0;

        cin >> n >> k >> sch;
        occ = 1;
        for (int i = 1; i < n; i++) {
            if (sch[i] == sch[i - 1]) occ++;
            else {
                node * this_freq = new node();
                this_freq -> val = occ;
                if (tail) {
                    tail -> next = this_freq;
                    this_freq -> prev = tail;
                    tail = this_freq;
                }
                else {
                    head = tail = this_freq;
                }
                occ = 1;
            }
        }
        node * this_freq = new node();
        this_freq -> val = occ;
        if (tail) {
            tail -> next = this_freq;
            this_freq -> prev = tail;
            tail = this_freq;
        }
        else {
            head = tail = this_freq;
        }

        //traverse(head);
        while(inversions_made < k)
            largest_node(head, true);
        //traverse(head);
        cout << largest_node(head, false) << "\n";
    }

    return 0;
}
