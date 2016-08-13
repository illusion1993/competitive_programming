#include <iostream>
#include <string>

using namespace std;

int n, m, fs;
string s;

void fsInit(){

    int count = 0, on = 0;
    for(int i = 0; i< n; i++){

        if(s[i] == '.' && on == 0) on = 1;
        else if(s[i] == '.' && on == 1){
            count++;
        }
        else if(s[i] != '.') on = 0;

    }

    fs = count;

}

int main(){

    int pos;
    char ch;

    cin>> n >> m >> s;
    fsInit();

    while(m--){

        cin >> pos >> ch;
        pos--;

        if(ch != '.' && (s[pos-1] == '.' && s[pos+1] == '.') && s[pos] == '.') fs-=2;
        else if(ch != '.' && (s[pos-1] == '.' || s[pos+1] == '.') && s[pos] == '.') fs--;

        else if(ch == '.' && s[pos] != '.' && (s[pos-1] == '.' && s[pos+1] == '.')) fs+=2;
        else if(ch == '.' && s[pos] != '.' && (s[pos-1] == '.' || s[pos+1] == '.')) fs++;

        s[pos] = ch;

        cout << fs << "\n";

    }

    return 0;

}
