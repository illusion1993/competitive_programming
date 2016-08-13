#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int mygcd;
void gcd(int first_number, int second_number){
    for(int i=1;i<=first_number&&i<=second_number;i++){
         if(first_number%i==0 && second_number%i == 0 ) mygcd=i;
    }
}

int main() {
    int T, r, s, collision_time, elapsed_time;
    float t, tmp_t;

    cin>>T;
    while(T--){
        cin>>r>>s;
        t = (float)s/4;

        int rem, div;
        rem = r % s;

        if(rem <= t) collision_time = r;
        else collision_time = r - rem + s;

        elapsed_time = collision_time - (s*(collision_time/s));

        gcd(elapsed_time, s);

        int numerator, denominator;
        if(mygcd==0) cout<<collision_time<<" 0/1"<<endl;
        else{
            numerator = elapsed_time/mygcd;
            denominator = s/mygcd;

            if(numerator==0 || denominator==0){
                numerator = 0;
                denominator = 1;
            }

            cout<<collision_time<<" "<<numerator<<"/"<<denominator<<endl;
        }
    }
    return 0;
}
