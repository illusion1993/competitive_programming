#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    string a, b;

    cin >> t;
    while(t--){

        cin >> a >> b;

        int *ptr = (int*)malloc((b.length() + 1) * sizeof(int));
        int *ptr1;

        for(int i = 0; i <= b.length(); i++) ptr[i] = i;

        for(int i = 1; i <= a.length(); i++){

            ptr1 = (int*)malloc((b.length() + 1)*sizeof(int));
            ptr1[0] = i;

            for(int j = 1; j <= b.length(); j++){

                if(a[i - 1] == b[j - 1]){
                    ptr1[j] = ptr[j - 1];
                }

                else{
                    ptr1[j] = min(ptr[j], ptr[j - 1]);
                    ptr1[j] = min(ptr1[j], ptr[j - 1]) + 1;
                }

            }

            free(ptr);
            ptr = ptr1;

        }

        cout << ptr[b.length()] << "\n";

    }

    return 0;
}
