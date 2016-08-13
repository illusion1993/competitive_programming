#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

vector<long long> calcFreq(vector<long long> &a, vector<long long> &b){

    vector<long long> freq;
    long long ptr1 = 0, ptr2 = 0, n, nn;

    while(ptr1 < a.size() && ptr2 < b.size()){

        if(a[ptr1] < b[ptr2]) ptr1++;
        else if(a[ptr1] > b[ptr2]) ptr2++;

        else{
            n = 1;
            nn = 1;
            ptr1++;
            ptr2++;

            while(a[ptr1] == a[ptr1 - 1]){
                ptr1++;
                n++;
            }

            while(b[ptr2] == b[ptr2 - 1]){
                ptr2++;
                nn++;
            }

            freq.push_back((n * nn) % mod);

        }

    }

    return freq;

}

int main(){

    long long n, m, c, elem;
    vector<long long> a, b, freq;

    cin >> n >> m >> c;

    for(long long i = 0; i < n; i++) {
        cin >> elem;
        a.push_back(elem);
    }

    for(long long i = 0; i < m; i++) {
        cin >> elem;
        b.push_back(elem);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    freq = calcFreq(a, b);

    long long *r1 = (long long*)malloc(freq.size() * sizeof(long long));
    long long *r2 = (long long*)malloc(freq.size() * sizeof(long long));

    long long sum = 0;
    for(long long i = 0; i < freq.size(); i++){
        sum = (sum + freq[i]) % mod;
        r1[i] = sum;
    }

    for(long long i = 1; i <= c; i++){
        for(long long j = 0; j < freq.size(); j++){
            if(j < i) r2[j] = 0;
            else{
                r2[j] = (((r1[j - 1] * freq[j]) % mod) + r2[j - 1]) % mod;
            }
        }
        cout << r2[freq.size() - 1] << " ";

        free(r1);
        r1 = r2;
        r2 = (long long*)malloc(freq.size() * sizeof(long long));
    }

    return 0;

}
