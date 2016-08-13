#include<iostream>
#include<string>
using namespace std;
int findMoves(int*,int,int);
int main(){
    int t;
    cin>>t;
    string str;
    int occ[26]={0};
    while(t--){
        cin>>str;
        int min,curr;
        int l=str.length();
        int occ[26]={0};
        int totalAlpha=0;
        for(int i=0; i<l; i++){
            if(occ[(int)str[i]-97]==0) totalAlpha++;
            occ[(int)str[i]-97]++;
        }
        min=-1;
        for(int i=totalAlpha; i>0; i--){
                if(l%i==0){
                    curr=findMoves(occ, i, l);
                    cout<<endl<<endl<<"function returned "<<curr<<" moves";
                    if(curr<min || min==-1) min=curr;
                    cout<<endl<<"min moves so far:"<<min;
                }
        }
        cout<<min<<endl;
    }
    return 0;
}
int findMoves(int *occ, int n, int l){
    int extras=0, shorts=0, avg=l/n;
    int diff[26], status[26]={0};

    cout<<endl<<endl<<"function called with n(req) and avg: "<<n<<" "<<avg<<endl;
    for(int i=0; i<26; i++){
        cout<<occ[i]<<" ";
    }

    for(int i=0; i<26; i++) diff[i]=(avg-occ[i]>0)?avg-occ[i]:occ[i]-avg;
    for(int j=0; j<n; j++){
            int thisDiff=l, thisAlpha, newDiff;
            for(int i=0; i<26; i++){
                newDiff=(avg-occ[i]>0)?avg-occ[i]:occ[i]-avg;
                if(occ[i]!=0 && status[i]==0 && newDiff<=thisDiff){
                    thisDiff=newDiff;
                    thisAlpha=i;
                }
            }
            status[thisAlpha]=1;
            if(occ[thisAlpha]>avg) extras+=occ[thisAlpha]-avg;
            else if(occ[thisAlpha]<avg) shorts+=avg-occ[thisAlpha];

            cout<<endl<<"alphabet selected with occurences: "<<occ[thisAlpha];
    }
    cout<<endl<<"extras are "<<extras<<" shorts are "<<shorts;
    if(shorts>=extras) return shorts;
    //else return
}
