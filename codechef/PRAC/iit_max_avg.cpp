#include<iostream>
using namespace std;
int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        long long max=-1, sum, avg;
        for(int i=2; i<=n; i++){
            for(int j=0; j<=n-i; j++){
                sum=0;
                for(int k=0; k<i; k++){
                    sum+=arr[j+k];
                }
                avg=sum/i;
                if(avg>max || max==-1) max=avg;
            }
        }
        cout<<max<<endl;
    }
}
