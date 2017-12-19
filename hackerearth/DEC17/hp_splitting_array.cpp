#include <bits/stdc++.h>
using namespace std;
 
struct node {
    int from, to, count;
    node *left, *right;
    node(int f, int t) {
        from = f;
        to = t;
        left = right = NULL;
        count = 0;
    }
};
 
node * make_node(int from, int to) {
    node * n = new node(from, to);
    if (from != to) {
        int mid = (from + to) / 2;
        n -> left = make_node(from, mid);
        n -> right = make_node(mid + 1, to);
    }
    return n;
}
 
void clear(node * n) {
    if (!n || !n -> count)
        return;
    clear(n -> left);
    clear(n -> right);
    n -> count = 0;
}
 
int count_less_than(node * n, int x) {
    int mid = (n -> from + n -> to) / 2;
    if (n -> from == n -> to && n -> from == x) return n -> count;
    if (x == mid) return n -> left -> count;
    if (x > mid) return n -> left -> count + count_less_than(n -> right, x);
    return count_less_than(n -> left, x);
}
 
void insert(node * n, int x) {
    n -> count += 1;
    if (n -> from != n -> to) {
        int mid = (n -> from + n -> to) / 2;
        if (x <= mid) insert(n -> left, x);
        else insert(n -> right, x);
    }
}
 
int t, n, arr[100000], s[100000];
vector< pair<int, int> > e_i;
node * root;
 
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    root = make_node(0, 1000000);
    while (t--) {
        long long inv_count = 0;
        e_i.clear();
        clear(root);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            inv_count += (i - count_less_than(root, arr[i]));
            insert(root, arr[i]);
            e_i.push_back(make_pair(arr[i], i));
        }
        sort(e_i.begin(), e_i.end());
        for (int i = 0; i < n; i++)
            s[e_i[i].second] = i;
        for (int i = 0; i < n; i++) {
            inv_count -= s[i];
            inv_count += n - s[i] - 1;
            cout << inv_count << " ";
        }
        cout << "\n";
    }
    return 0;
}