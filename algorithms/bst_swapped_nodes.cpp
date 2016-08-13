#include <bits/stdc++.h>

using namespace std;

struct node{

    int val;
    node *left, *right;

};

node *createTree(vector<int> &a, int rootIndex){

    node *root;
    root = NULL;

    if(rootIndex < a.size() && a[rootIndex] != -1){

        root = new node();

        root -> val = a[rootIndex];
        root -> left = createTree(a, ((rootIndex + 1) * 2) - 1);
        root -> right = createTree(a, ((rootIndex + 1) * 2));

    }

    return root;

}

void inorder(node *root){

    if(!root)
        return;

    inorder(root -> left);
    cout << root -> val << " ";
    inorder(root -> right);

}

void swap(node *first, node *second){

    int tmp = first -> val;
    first -> val = second -> val;
    second -> val = tmp;

}

void correctBST(node *root){

    static node *first, *second, *prev;

    if(root && (!first || !second)){

        correctBST(root -> left);

        if(prev == NULL) prev = root;

        else{

            if(root -> val < prev -> val && !first){
                first = prev;
            }

            else if(root -> val < prev -> val){
                second = root;
            }

            prev = root;

            if(first != NULL && second != NULL) swap(first, second);

        }

        correctBST(root -> right);

    }

}

int main(){

    int arr[] = {16, 11, 15, 10, 12, 14, 13, -1, -1, -1, -1, -1, -1, -1, -1};
    vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    node *root = createTree(vec, 0);
    inorder(root);
    cout << endl;

    correctBST(root);
    inorder(root);
    cout << endl;

    return 0;

}
