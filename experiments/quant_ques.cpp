#include<iostream>

using namespace std;

int main(){

    float cap1, cap2, full1, full2, a1, b1, a2, b2;
    int pour = 0;

    //cin>>cap1>>full1>>a1>>b1;
    //cin>>cap2>>full2>>a2>>b2;
    cap1 = 10;
    full1 = 9;
    a1 = 7;
    b1 = 2;
    cap2 = 20;
    full2 = 20;
    a2 = 18;
    b2 = 2;
    while(a1/b1 != a2/b2){
        if(full2 == cap2){
            a1 = a1 + (a2/(a2+b2))*(cap1 - full1);
            b1 = b1 + (b2/(a2+b2))*(cap1 - full1);
            full2 -= cap1 - full1;
            full1 = cap1;
            pour++;
            //cout<<"pour no: "<<pour<<endl<<" a1 = "<<a1<<" b1 = "<<b1<<" a2 = "<<a2<<" b2 = "<<b2<<" r1 = "<<a1 / b1<<" r2 = "<<a2 / b2<<endl<<endl;
            cout<<"pour no: "<<pour<<" r1 = "<<a1 / b1<<" r2 = "<<a2 / b2<<endl<<endl;
        }
        else if(full1 == cap1){
            a2 = a2 + (a1/(a1+b1))*(cap2 - full2);
            b2 = b2 + (b1/(a1+b1))*(cap2 - full2);
            full1 -= cap2 - full2;
            full2 = cap2;
            pour++;
            //cout<<"pour no: "<<pour<<endl<<" a1 = "<<a1<<" b1 = "<<b1<<" a2 = "<<a2<<" b2 = "<<b2<<" r1 = "<<a1 / b1<<" r2 = "<<a2 / b2<<endl<<endl;
            cout<<"pour no: "<<pour<<" r1 = "<<a1 / b1<<" r2 = "<<a2 / b2<<endl<<endl;
        }
        else{
            break;
        }
    }
    cout<<pour;

    return 0;
}
