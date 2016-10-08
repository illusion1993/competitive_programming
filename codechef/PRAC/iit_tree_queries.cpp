#include<iostream>
#include<vector>
using namespace std;
struct node{
    long long value;
    vector<int> next;
};
int count;
int traverse(node *nodes, int n){
    if(nodes[n-1].value==0) count++;
    for(int i=0; i<nodes[n-1].next.size(); i++){
        traverse(nodes, nodes[n-1].next[i]);
    }
    return 0;
}
int main(){
    int t, q;
    cin>>t>>q;
    //int edges[t-1][2];
    node n[t];
    int opcode1, opcode2;
    for(int i=0; i<t-1; i++){
        cin>>opcode1;
        cin>>opcode2;
        n[opcode1-1].next.push_back(opcode2);
    }
    //long long arr[t];
    for(int i=0; i<t; i++){
        cin>>n[i].value;
    }
    char op;
    //int opcode1, opcode2;
    while(q--){
        cin>>op;
        if(op=='Q'){
            cin>>opcode1;
            count=0;
            traverse(n, opcode1);
            cout<<count<<endl;
        }
        else{
            cin>>opcode1>>opcode2;
            n[opcode1-1].value=opcode2;
        }
    }
}
