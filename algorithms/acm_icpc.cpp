#include<iostream>
#include<string>
using namespace std;
int teamify(string *, int, int, int);
int main(){
    int n, m, max, count;
    cin>>n>>m;
    string arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    max=0;
    count=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(teamify(arr, i, j, m)>max){
                max=teamify(arr,i,j,m);
                count=1;
            }
            else if(teamify(arr,i,j,m)==max){
                count++;
            }
        }
    }
    cout<<max<<endl<<count;
    return 0;
}
int teamify(string *arr, int a, int b, int m){
    int count=0;
    for(int i=0; i<m; i++){
        if(arr[a][i]=='1' || arr[b][i]=='1') count++;
    }
    return count;
}
