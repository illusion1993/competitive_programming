#include<iostream>
#include<string>
using namespace std;
int inSecret(string, char, int);
int inSecret(string, char);
int main(){
    int t;
    cin>>t;
    string secret, message;
    while(t--){
        cin>>secret;
        cin.ignore(1,'\n');
        for(int i=secret.length()-1; i>-1; i--){
            if(inSecret(secret, secret[i], i)) secret.erase(i, 1);
        }
        getline(cin,message);

        int l=secret.length(), remainders=26-l, arraysize=(remainders%l==0)?remainders/l:(remainders/l)+1;

        string alphabets[arraysize];
        int ascii=65, index, count=0;
        char ch;
        while(ascii<91){
            ch=ascii;
            index=count/l;
            if(!inSecret(secret, ch)){
                alphabets[index].push_back(ch);
                count++;
            }
            ascii++;
        }
        string encryption;
        string secretsort=secret;
        for(int i=0; i<l; i++){
            for(int j=0; j<l; j++){
                if((int)secretsort[i]<(int)secretsort[j]) swap(secretsort[i], secretsort[j]);
            }
        }
        for(int i=0; i<l; i++){
            index=secret.find(secretsort[i]);
            encryption.push_back(secret[index]);
            for(int j=0; j<arraysize; j++){
                if(alphabets[j].length()>=index+1){
                    encryption.push_back(alphabets[j][index]);
                }
            }
        }
        string decryption;
        for(int i=0; i<26; i++){
            decryption.push_back((char)i+65);
        }
        l=message.length();
        for(int i=0; i<l; i++){
                if((int)message[i] > 64 && (int)message[i] < 92){
                    cout<<decryption[encryption.find(message[i])];
                }
                else cout<<message[i];
        }
        cout<<endl;
    }
    return 0;
}
int inSecret(string s, char c, int pos){
    int flag=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]==c && i!=pos) flag=1;
    }
    return flag;
}
int inSecret(string s, char c){
    int flag=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]==c) flag=1;
    }
    return flag;
}
