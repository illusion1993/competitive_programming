#include <bits/stdc++.h>

using namespace std;

void combine(vector<int> &coins, int sum, vector<int> &current, vector< vector<int> > &comb){

    for(int i = 0; i < coins.size(); i++){
        if((sum > coins[i] && current.size() == 0) || (sum > coins[i] && current.size() != 0 && current.back() <= coins[i])){
            current.push_back(coins[i]);
            combine(coins, sum - coins[i], current, comb);
            current.pop_back();
        }

        else if((sum == coins[i] && current.size() == 0) || (sum == coins[i] && current.size() != 0 && current.back() <= coins[i])){
            current.push_back(coins[i]);
            comb.push_back(current);
            current.pop_back();
        }
    }

}

int main(){

    vector<int> current, coins;
    vector< vector<int> > comb;
    int sum = 50;

    //coins.push_back(1);
    //coins.push_back(2);
    coins.push_back(3);
    coins.push_back(4);
    coins.push_back(5);

    sort(coins.begin(), coins.end());

    combine(coins, sum, current, comb);

    for(int i = 0; i < comb.size(); i++){
        for(int j = 0; j < comb[i].size(); j++){
            cout << comb[i][j] << " ";
        }
        cout << endl;
    }


    return 0;

}
