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

    int n = A.size();

    for(int i = 0; i < n; i++){
        if(A[i] < 0){
            negatives.push_back(i);
            cout << "pushing negative position" << i <<endl;
        }
    }

    int ptr = 0;
    long long sum;

    if(negatives.size()){

            for(int i = 0; i < negatives.size(); i++){
                    //if(ptr <= negatives[i]-1){
                        starts.push_back(ptr);
                        cout << "start pos " << ptr << endl;
                        ends.push_back(negatives[i]-1);
                        cout << "end pos " << negatives[i]-1 << endl;
                        sum = 0;

                        if(ptr == negatives[i]-1){
                            sum = A[ptr];
                        }
                        else{
                            for(int i = ptr; i < negatives[i]; i++) sum += A[i];
                        }

                        sums.push_back(sum);

                        cout << "sum for this range was " << sum << endl;
                    //}

                ptr = negatives[i]+1;

            }

    }
    else{
        starts.push_back(0);
        ends.push_back(n-1);
        sum = 0;

        for(int i = 0; i < n; i++) sum += A[i];

        sums.push_back(sum);

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

    int begin = starts[max_sum_index], stop = ends[max_sum_index], length = stop-begin+1;

    cout << length << " ";
    for(int i = begin; i <= stop; i++) cout << A[i] << " ";

    return 0;

}
