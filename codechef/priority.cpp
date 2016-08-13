#include<iostream>
using namespace std;
int main(){
    int n,i,next;
    cout<<"PRIRITY SCHEDULING EXAMPLE(NON-PREEMPTIVE)"<<endl<<endl<<"Enter the number of processes: ";
    cin>>n;
    int at[n], bt[n], p[n], s[n], time=0;
    for(i=0; i<n; i++){
        cout<<endl<<"Process "<<i+1<<endl<<"Arrival time: ";
        cin>>at[i];
        cout<<"Burst Time: ";
        cin>>bt[i];
        cout<<"Priority: ";
        cin>>p[i];
        s[i]=0;
    }
    next=0;
    for(i=0;i<n;i++){
        if(next!=i){
            if(at[i]<at[next]) next=i;
            else if(at[i]==at[next]){
                if(p[i]<p[next]) next=i;
            }
        }
    }
    while(next!=-1){
        time+=bt[next];
        s[next]=1;
        cout<<"Process "<<next+1<<" finished at time "<<time<<endl;
        next=-1;
        for(i=0; i<n; i++){
            if(s[i]==0){
                next=i;
                break;
            }
        }
        for(i=0; i<n; i++){

        }
    }
    return 0;
}
