#include<iostream>
#include<cmath>
using namespace std;
int findFives(int);
int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int zeroes=0, i;
        i=25;
        while(i<=n){
            zeroes+=findFives(i)-1;
            i+=25;
        }
        zeroes+=n/5;
        cout<<zeroes<<endl;
    }
    return 0;
}
int findFives(int n){
    int fives=0;
    int i=0, power;
    while(pow(5,i)<=n){
        power=pow(5,i);
        if(n%power==0) fives=i;
        i++;
    }
    return fives;
}
