#include <bits/stdc++.h>
using namespace std;

vector<int> findPattern(long long n){

    vector<int> ans;
    ans.push_back(n % 10);

    long long power = n * n;

    while(power % 10 != n % 10){
        ans.push_back(power % 10);
        power *= n;
    }

    return ans;

}

int main() {

    int t;
    long long a, b;
    vector<int> pattern;

    cin >> t;
    while(t--){

        cin >> a >> b;

        if(b == 0){
            cout << "1" << endl;
        }
        else{
            pattern = findPattern(a);

            cout << pattern[((b - 1) % pattern.size())] << endl;
        }

    }

	return 0;
}
