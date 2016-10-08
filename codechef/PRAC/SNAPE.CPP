#include<iostream>
#include<math.h>

using namespace std;

int main(){

    int t;
    float b, ls;

    cin>>t;
    while(t--){
        cin>>b>>ls;
        cout<<sqrt((ls*ls)-(b*b))<<" "<<sqrt((ls*ls)+(b*b))<<endl;
    }


    return 0;
}
