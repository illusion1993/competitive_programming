#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector <long> primes;
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
    primes.push_back(7);

    long range;
    int flag;
    cin>>range;

    for(long i=11; i<=range; i++){
        flag=1;
        for(long j=0; j<primes.size(); j++){
            if(i%primes[j]==0){
                flag=0;
                break;
            }
        }
        if(flag==1) primes.push_back(i);
    }

    for(long i=0; i<primes.size(); i++){
        cout<<primes[i]<<endl;
    }
    cout<<endl<<endl<<endl<<primes.size();
    return 0;
}
