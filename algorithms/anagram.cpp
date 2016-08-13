#include <iostream>
#include<string>
using namespace std;


int main() {
    int t;
    cin>>t;
    string s;
    int diff1, diff2;
    while(t--){
        cin>>s;
        int a[26]={0}, b[26]={0};
        if(s.length()%2==0){
            for(int i=0; i<s.length()/2; i++){
                a[(int)s[i]-97]++;
            }
            for(int i=s.length()/2; i<s.length(); i++){
                b[(int)s[i]-97]++;
            }
            diff1=0;
            diff2=0;
            for(int i=0; i<26; i++){
                    cout<<a[i]<<" ";
                if(a[i]>b[i]) diff1+=a[i]-b[i];
            }
            cout<<endl;
            for(int i=0; i<26; i++){
                    cout<<b[i]<<" ";
                if(b[i]>a[i]) diff2+=b[i]-a[i];
            }
            cout<<endl;
            if(diff1<diff2) cout<<diff1<<endl;
            else cout<<diff2<<endl;
        }
        else cout<<"-1"<<endl;
    }
    return 0;
}
