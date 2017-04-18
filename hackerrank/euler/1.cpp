#incldue<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long long sum = 0, n;
        cin >> n;
        sum += ((3 + (n - 1) - ((n - 1) % 3)) * ((n - 1) / 3)) / 2;
        sum += ((5 + (n - 1) - ((n - 1) % 5)) * ((n - 1) / 5)) / 2;
        sum -= ((15 + (n - 1) - ((n - 1) % 15)) * ((n - 1) / 15)) / 2;
        cout << sum << endl;
    }
    return 0;
}