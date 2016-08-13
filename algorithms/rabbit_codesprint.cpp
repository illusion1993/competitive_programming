#include <iostream>
using namespace std;
int main(){
    int t;
    long long min,max,p;
    cin>>t;
    while(t--){
        cin>>p;
        min=0;
        max=0;
        long long i=0;
        while(!(p>=min && p<=max)){
            i++;
            min+=i;
            max+=i+1;
        }
        cout<<i<<endl;
    }
    return 0;
}
