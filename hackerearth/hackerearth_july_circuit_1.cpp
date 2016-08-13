#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int occurence[26], pairs = 0, k, covered;

    cin >> k >> s;
    for(int i = 0; i <= s.length() - k; i++){
        memset(occurence, 0, 26);
        covered = 0;
        int j;
        for(j = i; j < i + k; j++){
            if(++occurence[(int)s[j] - 97] == 1){
                covered++;
            }
        }
        j--;
        while(covered <= k && j < s.length()){
            if(covered == k){
                pairs++;
                for(int a = i; a <= j; a++){
                    cout << s[a];
                }
                cout << endl;
            }
            j++;
            if(++occurence[(int)s[j] - 97] == 1){
                covered++;
            }
        }
    }
    cout << pairs;
    return 0;
}
