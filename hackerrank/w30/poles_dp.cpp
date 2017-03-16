#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<pair<int, int> > poles;    // <height, total_weight>...
int dp[5001][5001], top_stack[5001][5001];

void input() {
    int in1, in2;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> in1 >> in2;  // height, weight
        if (poles.size() && poles.back().first == in1) {
            poles.back().second += in2;
        }
        else {
            poles.push_back({in1, in2});
        }
    }
}

void print() {
    /*cout << "poles are: \n";
    for (int i = 0; i < poles.size(); i++) {
        cout << poles[i].first << " " << poles[i].second << "\n";
    }*/
    cout << "\nDp init values: \n";
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < poles.size(); j++) {
            cout << dp[i][j] << "/" << poles[top_stack[i][j]].first << "\t";
        }
        cout << endl;
    }
}

int find_dropping_cost(int highest_index, int drop_to) {
    int cost = 0;
    for (int i = drop_to + 1; i <= highest_index; i++) {
        cost += poles[i].second * (poles[i].first - poles[drop_to].first);
        //cout << "adding " << poles[i].first << " * (" << poles[i].second << " - " << poles[drop_to].second << ")\n";
    }
    //cout << "Dropping cost from index " << highest_index << " to " << drop_to << " is " << cost << endl;
    return cost;
}

int main() {
    input();
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < poles.size(); j++) {
            if (j <= i - 1) {
                dp[i][j] = 0;
                top_stack[i][j] = j;
                //cout << "Made dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
            }
            else if (i == 1) {
                dp[i][j] = dp[i][j - 1] + (poles[j].second * (poles[j].first - poles[0].first));
                top_stack[i][j] = 0;
                //cout << "Made dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
            }
            else {

                //cout << "Finding dp[" << i << "][" << j << "]\n";
                int min_dp = INT_MAX, min_top_stack, this_dp;

                // case 1; A new additional stack made on this height, keeping intact below stacks
                min_dp = dp[i - 1][j - 1];
                min_top_stack = j;
                //cout << "For case 1, if added new stack here, dp would be: " << min_dp << endl;

                // case 2: No stack made on this height, now iterate the last stack height to optimal pos
                // from top_stack[i][j - 1] ------ j
                //cout << "case 2, shifting the last stack upwards, starting to shift top from " << top_stack[i][j - 1] << " to " << j << endl;
                for (int new_top = top_stack[i][j - 1]; new_top <= j; new_top++) {
                    this_dp = dp[i - 1][new_top - 1] + find_dropping_cost(j, new_top);
                    if (this_dp < min_dp) {
                        min_dp = this_dp;
                        min_top_stack = new_top;
                    }
                }

                dp[i][j] = min_dp;
                top_stack[i][j] = min_top_stack;
            }
        }
    }
    //print();
    cout << dp[k][poles.size() - 1];

    return 0;
}
