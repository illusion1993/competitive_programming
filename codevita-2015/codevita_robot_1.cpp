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

            if(pos == fd) std::cout<<time<<" F"<<std::endl;
            else if(pos == bd) std::cout<<time<<" B"<<std::endl;
        }

        else{
            if(f < fd) std::cout<<"No Ditch"<<std::endl;
            else{
                std::cout<<t*fd<<" F"<<std::endl;
            }
        }

    }

    return 0;
}
