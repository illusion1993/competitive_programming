#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main(){
    vector<long long> list;
    for(int i=1; i<10; i++) list.push_back(i);
    //for(int i=0; i<list.size(); i++) cout<<list[i]<<" ";
    //cout<<endl<<"Total 9";
    //cout<<endl<<endl;

    long long count;
    for(int i=2; i<=9; i++){
        count=0;
        for(int j=0; j<list.size(); j++){
            if(list[j]*i >= pow(10, i-1) && list[j]*i < pow(10, i)){
                    list.push_back(list[j]*i);
                    //cout<<list[j]*i<<" ";
                    count++;
            }
        }
        //cout<<endl<<"Total "<<count;
        //cout<<endl<<endl;
    }
    for(int i=1; i<list.size(); i++) cout<<list[i]<<endl;
    return 0;
}
