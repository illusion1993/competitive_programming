#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(){

    string A;
while(1){











    cin >> A;

    long long total = 0, multiplier, fact_of, fact;

    for(int i = 0; i < A.length(); i++){
        multiplier = 0;
        for(int j = i + 1; j < A.length(); j++){
            if(A[j] < A[i]) multiplier++;
        }

        //cout << "For " << A[i] << " Multiplier is : " << multiplier << endl;

        fact_of = A.length() - 1 - i;
        fact = 1;

        for(long long i = 2; i <= fact_of; i++) fact = (fact * i) % 1000003;

        fact = (fact * multiplier) % 1000003;

        total = (total + fact) % 1000003;

    }

    cout << (total+1) % 1000003;












}

}
