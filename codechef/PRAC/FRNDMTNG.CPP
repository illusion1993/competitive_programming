#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    int t;
    float t1, t2, T1, T2, p1, p2;

    cin>>t;
    while(t--){
        cin>>T1>>T2>>t1>>t2;

        if(T2<T1){
            swap(T2, T1);
            swap(t2, t1);
        }

        if(T2 >= T1 + t1) p1 = t1/T2;

        else p1 = (((T2-t1)/T1) * (t1/T2)) + (((T1-T2+t1)/T1) * ((t1+T2-T1)/(2*T2)));

        p2 = (((T1-t2)/T2) * (t2/T1)) + ((t2*t2)/(2*T2*T1));


        std::cout << std::fixed << std::setprecision(6) << p1+p2 <<endl;
    }
    return 0;
}
