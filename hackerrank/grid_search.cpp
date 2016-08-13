#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>

using namespace std;

vector<string> arr, patt;
int t, R, C, r, c;

int search(int row, int col){
    cout<<"called"<<endl<<"r is "<<r<<"c is "<<c;
    int flag = 1;
    for(int i=0; i<r; i++){
        cout<<"loop 1";
        for(int j=0; j<c; j++){
            cout<<"loop 2";
            cout<<"checking "<<arr[row+i][col+j]<<" against "<<patt[i][j]<<" -> ";
            if(arr[row+i][col+j] != patt[i][j]){
                flag = 0;
                break;
                break;
            }
        }
    }

    return flag;
}

int main() {
    cin>>t;
    while(t--){
        cin>>R>>C;
        cout<<endl<<"(MAIN) R is "<<R<<" C is "<<C<<endl;
        string s;
        for(int i=0; i<R; i++){
            cin>>s;
            arr.push_back(s);
        }
        for(int i=0; i<R; i++){
            cout<<arr[i]<<endl;
        }
        /*
        cin>>r>>c;
        cout<<endl<<"(MAIN) r is "<<r<<" c is "<<c<<endl;
        for(int i=0; i<r; i++){
            cin>>patt[i];
        }

        int flag = 0;
        for(int i=0; i<=R-r; i++){
            for(int j=0; j<=C-c; j++){
                if(search(i, j) == 1){
                    flag = 1;
                    break;
                    break;
                }
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        */
    }
    return 0;
}
