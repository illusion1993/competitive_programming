#include<iostream>
using namespace std;
int allFallen(int *arr, int n){
    int count=0;
    for(int i=0; i<n; i++){
        if(arr[i]!=0 && arr[i]!=(n+1)*2){
            count++;
        }
    }
    if(count==1 || count==2) return count;
    else return 0;
}
int main(){
    int n;
    cin>>n;
    int speed[n], pos[n], end1=0, end2=(n+1)*2;
    for(int i=0; i<n; i++){
        cin>>speed[i];
        pos[i]=(i+1)*2;
    }
    int time=0;
    while(!allFallen(pos, n)){
        time++;
        for(int i=0; i<n; i++){
            if(pos[i]!=0 && pos[i]!=(n+1)*2){
                pos[i]+=speed[i];
            }
        }
        for(int i=0; i<n-1; i++){
            if(pos[i]==pos[i+1]){
                speed[i]*=-1;
                speed[i+1]*=-1;
            }
        }
    }
    if(allFallen(pos, n)==1){
        for(int i=0; i<n; i++){
            if(pos[i]!=0 && pos[i]!=(n+1)*2) cout<<n+1<<endl;
        }
    }
    else if(allFallen(pos, n)==2){
        int ant1=-1, ant2;
        for(int i=0; i<n; i++){
            if(pos[i]!=0 && pos[i]!=(n+1)*2 && ant1==-1) ant1=i;
            else if(pos[i]!=0 && pos[i]!=(n+1)*2 && ant1!=-1) ant2=i;
        }
        if(speed[ant1]*speed[ant2]==-1){
            if(pos[ant1]>=((n+1)*2)-pos[ant2]) cout<<ant1+1;
            else cout<<ant2+1;
        }
        else{
            if(speed[ant1]==1) cout<<ant1+1;
            else cout<<ant2+1;
        }
    }
    return 0;
}
