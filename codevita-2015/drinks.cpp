#include<iostream>

int main(){

    int t, n, x, flag;

    flag = 0;
    std::cin>>n;
    int drinks[n];
    for(int i=0; i<n; i++){
        std::cin>>drinks[i];
    }
    std::cin>>x;

    for(int i=0; i<n; i++){
        for(int j=1; j<n; j++){
            for(int k=2; k<n; k++){

                if(i != j && j != k){
                    if(drinks[i] + drinks[j] + drinks[k] == x) flag = 1;
                }

            }
        }
    }

    if(flag == 0) std::cout<<"False";
    if(flag == 1) std::cout<<"True";

    return 0;
}
