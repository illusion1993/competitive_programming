#include<iostream>

using namespace std;

int main(){
    int t, n, c[51], total, flag, a[51], ptr;
    cin>>t;
    while(t--){
        total=0;
        flag=1;
        cin>>n;
        c[0]=0;
        for(int i=0; i<n; i++) cin>>c[i+1];

        for(int i=1; i<=n; i++){
            total+=c[i];
            if(c[i]>n-1) flag=0;
        }
        if(total!=n) flag=0;
        if(flag){
            ptr=1;
            for(int i=1; i<=n; i++){
                for(int j=0; j<c[i]; j++){
                    a[ptr]=i;
                    ptr++;
                }
            }
            for(int i=1; i<=n; i++){
                if(a[i]==i){
                    for(int j=1; j<=n; j++){
                        if(a[i]!=a[j]){
                            int tmp = a[i];
                            a[i]=a[j];
                            a[j]=tmp;

                            break;
                        }
                    }
                }
            }
            for(int i=1; i<=n; i++) cout<<a[i]<<" ";
            cout<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
    return 0;
}
