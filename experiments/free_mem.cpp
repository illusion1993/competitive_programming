#include<bits/stdc++.h>
using namespace std;

struct node{

    int data;
    node *next;

};

int main(){

    node *n = new node();
    n -> data = 9;

    cout << n << endl << n -> data;
    free(n);
    cout << n << endl << n -> data;

	return 0;

}
