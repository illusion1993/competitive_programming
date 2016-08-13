#include<bits/stdc++.h>
using namespace std;

struct node{
    long long data;
    node *next;
};

node* createList(long long m, long long n){

    node *head = new node();

    if(m == 1) m++;

    if(m == 2){
        head -> data = m;
        m++;
    }

    else if(m % 2 == 0){
        m++;
        head -> data = m;
        m += 2;
    }

    else{
        head -> data = m;
        m += 2;
    }

    node *ptr;
    ptr = head;

    for(long long i = m; i <= n; i += 2){
        node *newNode = new node();
        newNode -> data = i;
        ptr -> next = newNode;
        ptr = newNode;
    }
    ptr -> next = NULL;

    return head;

}

node* checkBy(long long a, node *head){

    node *ptr, *ptr1;

    while(head -> data % a == 0 && head -> data != a){
        ptr = head;
        head = head -> next;
        free(ptr);
    }

    ptr = head;
    ptr1 = head -> next;

    while(ptr1 != NULL){
        if(ptr1 -> data % a == 0 && ptr1 -> data != a){
            ptr -> next = ptr1 -> next;
            free(ptr1);
            ptr1 = ptr -> next;
        }
        else{
            ptr = ptr -> next;
            ptr1 = ptr1 -> next;
        }
    }

    return head;

}

void freeMem(node *head){

    node *ptr, *ptr1;
    ptr = head;
    ptr1 = ptr -> next;

    while(ptr1 != NULL){
        free(ptr);
        ptr = ptr1;
        ptr1 = ptr1 -> next;
    }

    free(ptr);

}

int main(){

    int t;
    long long m, n;

    cin >> t;
    while(t--){

        cin >> m >> n;
        node *head = createList(m, n);
        node *ptr;

        ptr = head;

        for(long long i = 2; i < sqrt(n); i++){
            head = checkBy(i, head);
        }

        while(ptr != NULL){
            cout << ptr -> data << "\n";
            ptr = ptr -> next;
        }

        //freeMem(head);

    }

	return 0;

}
