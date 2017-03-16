#include <bits/stdc++.h>
using namespace std;

int n, s, poles[5000][2], min_cost;
vector<pair<int, vector<int> > > height_poles;  //<height, <w1, w2, w3...> >...
vector<int>final_stack_heights;

void find_cost(vector<int> stack_heights) {
    int current_stack_height = stack_heights.size() - 1, cost = 0;
    for (int i = height_poles.size() - 1; i >= 0; i--) {
        if (height_poles[i].first > stack_heights[current_stack_height]) {
            for (int j = 0; j < height_poles[i].second.size(); j++) {
                cost += height_poles[i].second[j] * (height_poles[i].first - stack_heights[current_stack_height]);
            }
        }
        else {
            current_stack_height--;
        }
    }
    min_cost = min(min_cost, cost);

    if (min_cost == cost) final_stack_heights = stack_heights;
}

void make_stacks(vector<int> stacks_so_far, int index) {
    if (stacks_so_far.size() == s) {
        find_cost(stacks_so_far);
    }
    else {
        if (height_poles.size() - index > s - stacks_so_far.size()) {
            make_stacks(stacks_so_far, index + 1);
        }
        stacks_so_far.push_back(height_poles[index].first);
        make_stacks(stacks_so_far, index + 1);
    }
}

int main() {
    min_cost = INT_MAX;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> poles[i][0] >> poles[i][1];
        if (height_poles.size() && height_poles.back().first == poles[i][0]) {
            height_poles.back().second.push_back(poles[i][1]);
        }
        else {
            vector<int> v;
            v.push_back(poles[i][1]);
            height_poles.push_back({poles[i][0], v});
        }
    }

    vector<int> stacks_so_far;
    stacks_so_far.push_back(poles[0][0]);
    make_stacks(stacks_so_far, 1);
    cout << min_cost;

    cout << endl <<"Final stack heights: \n";
    for (int i  = 0; i < final_stack_heights.size(); i++) cout << final_stack_heights[i] << endl;
    return 0;
}
