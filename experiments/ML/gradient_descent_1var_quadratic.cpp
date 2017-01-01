#include<iostream>

using namespace std;

float alpha = 0.1, lastFx, x, Fx, DFx, a, b, c, threshold = 0.00001;

int main(){

    cout<<"Enter the variables a, b and c of quadratic equation: ";
    cin>>a>>b>>c;
    cout<<"Now enter the initial position of the variable x : ";
    cin>>x;

    lastFx = (a*x*x) + (b*x) + c;
    DFx = (2*a*x) + b;
    x = x - (alpha*DFx);
    Fx = (a*x*x) + (b*x) + c;

    cout<<endl<<"x = "<<x<<", F(x) = "<<Fx;

    while(Fx < lastFx && lastFx-Fx > threshold){
        lastFx = (a*x*x) + (b*x) + c;
        DFx = (2*a*x) + b;
        x = x - (alpha*DFx);
        Fx = (a*x*x) + (b*x) + c;

        cout<<endl<<"x = "<<x<<", F(x) = "<<Fx;
    }

    cout<<endl<<endl<<"Local minima found near x = "<<x<<", and F(x) = "<<Fx;
    return 0;
}
