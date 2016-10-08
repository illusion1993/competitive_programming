#include<iostream>

using namespace std;

int main(){
    int t, n, prev, cur, alloc;
    cin>>t;
    while(t--){
        cin>>n;
        prev=0;
        alloc=0;

        while(n--){
            cin>>cur;
            if(cur>prev) alloc+=cur-prev;

            prev=cur;
        }
        cout<<alloc<<endl;
    }
    return 0;
}
