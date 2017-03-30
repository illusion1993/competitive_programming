#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{

    string A = "IDIID";
    int n = 6;

    int minima, maxima, minima_index;
    minima = maxima = minima_index = 0;
    vector<int> ans(A.length() + 1);
    ans[0] = 0;
    
    for (int i = 0; i < A.length(); i++) {
        if (A[i] == 'D') {
            minima--;
            //minima_index = i + 1;
            ans[i + 1] = minima;
        }
        else {
            maxima++;
            ans[i + 1] = maxima;
        }
    }

    int add_fac = 1 - minima;
    for (int i = 0; i < ans.size(); i++) {
        ans[i] += add_fac;
    }

    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}    