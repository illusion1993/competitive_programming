#include<iostream>
using namespace std;

int main(){
    int n, f, b, t, fd, bd, time, pos, m;
    cin>>n;

    while(n--){
        time=0;
        pos = 0;
        cin>>f>>b>>t>>fd>>bd;
        if(f != b){
            bd *= -1;

            int c = 2;
            while(1){
                m = f;
                while(pos != fd && m != 0){
                        pos += 1;
                        time += t;
                        cout<<"moving forward, m is set "<<m<<" pos is now "<<pos<<" time is now "<<time<<endl;

                        m--;
                }
                m = b;
                while(pos != bd && m != 0){
                        pos -= 1;
                        time += t;
                        cout<<"moving backward, m is set "<<m<<" pos is now "<<pos<<" time is now "<<time<<endl;

                        m--;
                }

                cout<<"finally pos is "<<pos<<" fd is "<<fd<<" bd is "<<bd;
            }

            if(pos == fd) cout<<time<<" F";
            else if(pos == bd) cout<<time<<" B";
            cout<<"pos was :"<<pos;
        }

        else{
            if(f < fd) cout<<"No Ditch"<<endl;
            else{
                cout<<t*fd<<" F"<<endl;
            }
        }

    }

    return 0;
}
