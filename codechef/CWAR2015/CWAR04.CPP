#include<bits/stdc++.h>

using namespace std;

bool inList(vector<int> current, int n){

    for(int i = 0; i < current.size(); i++){
        if(current[i] == n) return true;
    }

    return false;

}

int costOf(vector<int> &order, vector< vector<int> > &queries){

    int l = queries[0].size();
    int arr[l], cost = 0, fresh;

    fill_n(arr, l, 0);

    for(int i = 0; i < order.size(); i++){

        int q_no = order[i] - 1;
        fresh = 0;
        for(int j = 0; j < queries[q_no].size(); j++){
            if(queries[q_no][j] == 1 && arr[j] == 0){
                arr[j] = 1;
                fresh++;
            }
        }
        cost += fresh*fresh;

    }

    return cost;

}

void comb(int n, vector<int> &current, vector<int> &costs, vector< vector<int> > &queries){

    if(current.size() == n){
        costs.push_back(costOf(current, queries));
    }

    else{
        for(int i = 1; i <= n; i++){
            if(!inList(current, i)){
                current.push_back(i);
                comb(n, current, costs, queries);
                current.pop_back();
            }
        }
    }

}

int main(){

    string s;
    vector<int> current, costs, query;
    vector< vector<int> > queries;

    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1') query.push_back(1);
        else if(s[i] == '0') query.push_back(0);
        else{
            queries.push_back(query);
            query.clear();
        }
    }
    if(query.size()) queries.push_back(query);

    if(queries.size() && queries[0].size()){

        for(int i = 1; i <= queries[0].size(); i++){
            current.clear();
            current.push_back(i);
            comb(queries[0].size(), current, costs, queries);
        }

        int minCost = costs[0];

        for(int i = 0; i < costs.size(); i++){
            if(minCost > costs[i]) minCost = costs[i];
        }

        cout << minCost;

    }

    else cout << "0";


    return 0;

}
