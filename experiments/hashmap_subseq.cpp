#include <bits/stdc++.h>

using namespace std;

#define key 31
#define mod 10000

bool occur[10000];

int generate_hash(long long n){
    cout << "Generating hash for " << n << endl;
    int hsh = 0;
    while(n){
        hsh = (hsh * key + n%10 + 1)%mod;
        n /= 10;
    }
    cout << "Hash is " << hsh << endl;
    return hsh;
}


int main(){

    long long n = 236889;
    cout << "n is " << n << endl << "Setting occur = false upto 10,000" << endl;
    memset(occur,false,sizeof occur);
    long long product[20],dig = 1;
    product[0] = 1;
    cout << "setting product[0] = " << product[0] << endl;
    cout << "While n, n /= 10 each step," << endl;
    while(n){
        cout << "the dig is " << dig << endl;
        cout << "product[" << dig << "] = product[" << dig-1 << "] * " << n%10 << " = " << product[dig - 1]*(n%10) << endl;
        product[dig] = product[dig - 1]*(n%10);
        n /= 10;
        ++dig;
    }
    cout << "While loop completed" << endl;
    bool flag = true;
    cout << "Flag = true" << endl;
    for(int i = 1;i < dig; ++i){
        cout << "i is " << i << endl;
        for(int j = i;j < dig; ++j){
            cout << "j is " << j << endl;

            long long subpro = product[j]/product[i - 1];

            cout << "subpro = product[j]/product[i - 1] = " << product[j] << "/" << product[i - 1] << " = " << product[j]/product[i - 1] << endl;
            int hsh = generate_hash(subpro);
            cout << "hsh = hash of subpro = " << hsh << endl;
            if(occur[hsh] == true){
                cout << "since occur[hsh] == true, flag will be false now------------------------------------------------------------->" << endl;
                flag = false;
            }
            cout << "setting occur[hsh] = true" << endl;
            occur[hsh] = true;
        }
    }
    if(flag)
        cout << "Colorful";
    else
        cout << "Not colorful";

    return 0;


}
