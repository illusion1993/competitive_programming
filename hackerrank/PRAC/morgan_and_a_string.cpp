#include<iostream>
#include<string>
using namespace std;

int main(){
    int t, edge, hinge;
    cin>>t;
    string a,b;
    int p1,p2,t1,t2,l1,l2;
    while(t--){
        edge=-1;
        hinge=-1;
        cin>>a>>b;
        l1=a.length();
        l2=b.length();
        p1=0;
        p2=0;
        while(p1<l1 && p2<l2){
            if((int)a[p1]<(int)b[p2]){
                cout<<a[p1];
                p1++;
            }
            else if((int)a[p1]>(int)b[p2]){
                cout<<b[p2];
                p2++;
            }
            else{
                if(edge==-1 && hinge==-1){
                    t1=p1;
                    t2=p2;
                    while(t1<l1 && t2<l2 && a[t1]==b[t2]){
                        t1++;
                        t2++;
                    }
                    if(t1==l1){
                        edge=0;
                        hinge=t1;
                    }
                    else if(t2==l2){
                        edge=1;
                        hinge=t2;
                    }
                    else if(t1!=l1 && t2!=l2){
                        if((int)a[t1]<(int)b[t2]){
                            edge=0;
                            hinge=t1;
                        }
                        else if((int)a[t1]>(int)b[t2]){
                            edge=1;
                            hinge=t2;
                        }
                    }
                }
                if(edge==0){
                    cout<<a[p1];
                    p1++;
                    if(p1==hinge){
                        edge=-1;
                        hinge=-1;
                    }
                }
                else if(edge==1){
                    cout<<b[p2];
                    p2++;
                    if(p2==hinge){
                        edge=-1;
                        hinge=-1;
                    }
                }
            }
        }
        cout<<a.substr(p1)<<b.substr(p2);
        cout<<endl;
    }
    return 0;
}
