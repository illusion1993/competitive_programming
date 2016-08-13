#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
    int res, ans, score=0, chances=0;
    do{
        res = rand() % 10 + 1;

        cout<<endl<<endl<<"enter prediction: ";
        cin>>ans;

        if(ans==res){
            cout<<"Right! Random was "<<res;
            score++;
            chances++;
        }
        else{
            cout<<"Wrong! Random was "<<res;
            chances++;
        }
    }
    while(ans!=0);
    cout<<endl<<endl<<"score is: "<<(float)score/(float)chances;
    return 0;
}
