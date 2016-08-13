#include<bits/stdc++.h>
using namespace std;
double prob(double T1, double T2, double t1, double t2){
    double above, below;
    if(T1 <= T2){
        above = (T2 - T1/2.0)/(T2);
    }
    else
        above = (T2/(2.0*T1));
    if(t1 >= T2)
        below = 1.0;
    else{
        if((t1+T1) <= T2){
            below = (T1/2.0 + t1)/T2;
        }
        else{
            below = ((T1*T2) - ((T2-t1)*(T2-t1))/2.0)/(T1*T2);
        }
    }
    cout<<"above is :"<<above<<endl;
    cout<<"below is :"<<below<<endl;
    return (below - above);


}
int main(){

    int t;
    cin >> t;
    double t1,t2,T1,T2,p;
    while(t--){
        scanf("%lf %lf %lf %lf",&T1,&T2,&t1,&t2);
        p = prob(T1,T2,t1,t2) + prob(T2,T1,t2,t1);
        printf("%.8lf\n",p);
    }
    return 0;

}
