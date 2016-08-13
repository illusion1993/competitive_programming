#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector<int> starts, ends, A;
    vector<int> negatives;
    vector<long long> sums;

    A.push_back(756898537);
    A.push_back(-1973594324);
    A.push_back(-2038664370);
    A.push_back(-184803526);
    A.push_back(1424268980);
    //A.push_back(5);

    int n = A.size(), start = 0, stop;
    long long sum = 0;

    for(int i = 0; i < n; i++){
        if(A[i] < 0 && start != -1){
            sums.push_back(sum);
            starts.push_back(start);
            ends.push_back(stop);

            start = -1;
            sum = 0;
        }
        else{
            sum += A[i];
            stop = i;
            if(start == -1) start = i;
        }

        if(i == n-1 && start != -1){
            sums.push_back(sum);
            starts.push_back(start);
            ends.push_back(stop);

            start = -1;
            sum = 0;
        }
    }

    int max_sum_index = -1;
    long long max_sum = sums[0];

    for(int i = 0; i < sums.size(); i++){
        if(sums[i] > max_sum) max_sum = sums[i];
    }

    for(int i = 0; i < sums.size(); i++){
        if(sums[i] == max_sum && max_sum_index == -1) max_sum_index = i;

        else{
            if(sums[i] == max_sum && ends[i]-starts[i] > ends[max_sum_index]-starts[max_sum_index]) max_sum_index = i;
        }
    }

    int begin = starts[max_sum_index], end = ends[max_sum_index], length = end-begin+1;

    //cout << length << " ";
    for(int i = begin; i <= end; i++) cout << A[i];

    return 0;

}
