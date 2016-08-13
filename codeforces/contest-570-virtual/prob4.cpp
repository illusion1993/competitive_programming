#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node{
    int depth, parent;
    vector<int> children;
    char value;
};

vector<node> tree;
vector<char> found;
int occ[26];

void traverse(int vi, int hi){
    if(tree[vi].depth == hi) found.push_back(tree[vi].value);
    else if(tree[vi].depth < hi){
        for(int i = 0; i < tree[vi].children.size(); i++){
            traverse(tree[vi].children[i], hi);
        }
    }
}

void checkPall(){
    for(int i = 0; i < 26; i++) occ[i] = 0;
    for(int i = 0; i < found.size(); i++){
        occ[(int)found[i] - 97]++;
    }
    int flag = 0, pall = 1;
    for(int i = 0; i < 26; i++){
        if(occ[i] % 2 != 0 && flag == 0) flag = 1;
        else if(occ[i] % 2 != 0 && flag == 1) pall = 0;
    }

    if(pall == 1) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
}

int main(){

    int n, m, p;
    string s;
    cin >> n >> m;

    node root;
    root.depth = 1;
    root.parent = 0;

    tree.push_back(root);

    for(int i = 1; i < n; i++){
        cin >> p;
        p--;
        tree[p].children.push_back(i);

        node child;
        child.depth = tree[p].depth + 1;
        child.parent = p;
        tree.push_back(child);
    }

    cin >> s;
    for(int i = 0; i < n; i++){
        tree[i].value = s[i];
    }

    int vi, hi;
    for(int i = 0; i < m; i++){
        cin >> vi >> hi;
        found.clear();
        vi--;
        traverse(vi, hi);
        checkPall();
    }

    return 0;

}
