#include <bits/stdc++.h>

using namespace std;

int main(){

    int a[]  = {603, 547, 457, 452, 330, 232, 200};
    int l = 7;

    int profit[7], lowest;
    profit[0] = 0;
    profit[1] = a[1] - a[0];

    if(a[0] <= a[1]) lowest = 0;
    else lowest = 1;

    for(int i = 2; i < l; i++){

        profit[i] = max(profit[i - 1], a[i] - a[lowest]);

        if(a[i] < a[lowest]) lowest = i;

    }

    for(int i = 0; i < 7; i++) cout << profit[i] << " ";

    return 0;

}
