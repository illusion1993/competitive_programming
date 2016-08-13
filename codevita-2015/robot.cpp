#include<iostream>

int main(){
    int n, f, b, t, fd, bd, time, pos, m;
    std::cin>>n;

    while(n--){
        time=0;
        pos = 0;
        std::cin>>f>>b>>t>>fd>>bd;

        if(f != b){
            bd = bd * -1;
            while(pos != fd && pos != bd){
                if(pos + f < fd){
                    pos += f;
                    time += f*t;
                }
                else{
                    time += (fd - pos)*t;
                    pos = fd;
                }

                if(pos != fd && pos - b > bd){
                    pos -= b;
                    time += b*t;
                }
                else if(pos != fd && pos - b <= bd){
                    time += (pos - bd)*t;
                    pos = bd;
                }
            }

            if(pos == fd) std::cout<<time<<" F";
            else if(pos == bd) std::cout<<time<<" B";

            if(n > 0) std::cout<<std::endl;
        }

        else{
            if(f < fd){
                std::cout<<"No Ditch";
                if(n > 0) std::cout<<std::endl;
            }
            else{
                std::cout<<t*fd<<" F";
                if(n > 0) std::cout<<std::endl;
            }
        }

    }

    return 0;
}
