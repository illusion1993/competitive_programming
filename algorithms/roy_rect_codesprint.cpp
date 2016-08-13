#include <iostream>
using namespace std;
int main() {
    long long int x,y,t,x1,y1,x2,y2,tmp;
    cin>>t;
    while(t--){
        cin>>x>>y>>x1>>y1>>x2>>y2;
        tmp=((x-x1)>0)?(x-x1):-1*(x-x1);
        tmp=((x-x2)>0)?((x-x2)<tmp)?(x-x2):tmp:(-1*(x-x2)<tmp)?-1*(x-x2):tmp;
        tmp=((y-y2)>0)?((y-y2)<tmp)?(y-y2):tmp:(-1*(y-y2)<tmp)?-1*(y-y2):tmp;
        tmp=((y-y1)>0)?((y-y1)<tmp)?(y-y1):tmp:(-1*(y-y1)<tmp)?-1*(y-y1):tmp;
        cout<<tmp<<endl;
    }
    return 0;
}
