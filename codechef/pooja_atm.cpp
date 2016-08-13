#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int x;
    float b;
    cin>>x;
    cin>>b;
    if((x%5==0)&&(b>=x+0.50)) b-=x+0.50;
    cout<<fixed<<setprecision(2) << b;
    return 0;
}
