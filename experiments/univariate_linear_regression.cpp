#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<float> x;
vector<float> y;

float m = 0.0, c = 0.0, alpha = 0.00001, max_allowed_RMS_error = 0.001;

float findRMS(){

    float error = 0.0, in, out, pred;

    for(int i = 0; i < x.size(); i++){
        in = x[i];
        out = y[i];
        pred = ((m * in) + c);

        error += (pred - out) * (pred - out);
    }

    error /= x.size();
    error = sqrt(error);

    return error;

}

float update_m(){

        float d = alpha, old_m, old_cost, cost, derivative;
        old_m = m;
        old_cost = findRMS();
        m = m + d;
        cost = findRMS();

        derivative = (cost - old_cost) / (m - old_m);

        m = old_m;
        return old_m - (alpha * derivative);

}

float update_c(){

        float d = alpha, old_c, old_cost, cost, derivative;
        old_c = c;
        old_cost = findRMS();
        c = c + d;
        cost = findRMS();

        derivative = (cost - old_cost) / (c - old_c);

        c = old_c;
        return old_c - (alpha * derivative);

}

int main(){

    int t;
    float in, out, new_m, new_c;

    cout << "Enter number of training examples : ";
    cin >> t;

    while(t--){
        cout << "Enter input value : ";
        cin >> in;
        cout << "Enter output value : ";
        cin >> out;
        cout << endl;

        x.push_back(in);
        y.push_back(out);
    }

    while(findRMS() > max_allowed_RMS_error){

        new_m = update_m();
        new_c = update_c();

        m = new_m;
        c = new_c;

    }

    //cout << "value of m is " << m << " value of c is " << c << " RMS error is " << findRMS();

    cout<< endl << "The hypothesis function is found to be : y = " << m << "x + " << c << endl;
    cout << "Enter number of testing examples : ";
    cin >> t;

    while(t--){
        cout << endl << "Enter input value : ";
        cin >> in;
        cout << "Predicted output value : " << (m * in) + c;
        cout << endl;
    }

    return 0;

}
