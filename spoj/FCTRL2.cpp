#include <bits/stdc++.h>
using namespace std;

vector<int> multiply(vector<int> &a, int b){

    /*
    cout << "multiplying : ";
    for(int i = 0; i < a.size(); i++) cout << a[i];
    cout << " with " << b << endl;
    */

    vector<int> ans;
    int carry = 0, mult;

    for(int i = a.size() - 1; i >= 0; i--){
        mult = (a[i] * b) + carry;
        ans.push_back(mult % 10);
        carry = mult / 10;
    }

    while(carry){
        ans.push_back(carry % 10);
        carry /= 10;
    }

    reverse(ans.begin(), ans.end());

    return ans;

}

vector< vector<int> > compute(){

    vector< vector<int> > ans;
    vector<int> current;
    current.push_back(1);
    ans.push_back(current);

    int carry;

    for(int i = 1; i <= 100; i++){

        carry = 0;
        current.clear();

        current = multiply(ans[i - 1], i);

        ans.push_back(current);

    }

    return ans;


}

int main() {

    int t, n;
    vector< vector<int> > table = compute();

    cin >> t;
    while(t--){
        cin >> n;

        vector<int> ans = table[n];

        for(int i = 0; i < ans.size(); i++) cout << ans[i];

        cout << endl;

    }

	return 0;
}
