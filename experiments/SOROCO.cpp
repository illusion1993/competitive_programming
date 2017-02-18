#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, tmp_in, power_of_2, total_power_of_2;
    long sum;
    //vector<int> a;
    cin >> t;

    while(t--) {
        //a.clear();
        total_power_of_2 = 0;
        sum = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp_in;

            if (tmp_in % 2) sum += tmp_in;

            else{
                cout << "For input " << tmp_in << ", Place value is: ";
                power_of_2 = 0;
                while(tmp_in % (int)pow(2, power_of_2) == 0) power_of_2++;
                power_of_2--;
                if (tmp_in / pow(2, power_of_2) > 1)
                    sum += (tmp_in / pow(2, power_of_2));
                cout << (tmp_in / pow(2, power_of_2)) << " * (2^" << power_of_2 + i << ")" << endl;
                sum += 1;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}
