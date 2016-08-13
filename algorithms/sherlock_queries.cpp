#include<iostream>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    int A[n], B[m], C[m];
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    for(int i=0; i<m; i++){
        cin>>B[i];
    }
    for(int i=0; i<m; i++){
        cin>>C[i];
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
                if(B[i]!=0){
                    if(j%B[i]==0) A[j]=(A[j]*C[i])%1000000007;
                }
        }
    }
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    return 0;
}
