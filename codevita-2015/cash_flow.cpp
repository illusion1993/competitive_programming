#include<iostream>
#include<math.h>

using namespace std;

int main(){

    double m, t, r;
    cin>>m>>t>>r;

    if(r != 0){
        double pr = (double)(r/12)/100;
        double a = (double)(1-pow((1+pr), (-1*t)))/pr;
        double pv = (double)m*a;

        cout<<round(pv);
    }

    else{
        cout<<round(m*t);
    }

    return 0;
}
