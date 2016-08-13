#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

float priceof(const vector<float> &x, const vector<float> &y){
    float sum = 0.0;

    int n = x.size();
    for(int i=0; i < n; i++){
        sum += x[i] * y[i];
    }

    return sum;
}

float costfunc(const vector<vector<float> > &characteristics, const vector<float> &prices, const vector<float> &factors, int n, int c){
    vector<float> h(n);
    float sum = 0.0;

    for(int i = 0; i < n; i++){
        h[i] = priceof(characteristics[i], factors);
        sum += (h[i]-prices[i]) * (h[i]-prices[i]) / (2*(n));
    }

    return sum;
}

void printfactors(const vector<float> & factors){
    int n = factors.size();
    cout << "factors: ";
    for(int i = 0; i < n; i++)
        cout << factors[i] << " ";

    cout << endl;
}

void gradientdescent(const vector<vector<float> > &characteristics, const vector<float> &prices, vector<float> &factors, int n, int c, float alpha){
    vector<float> h(n);
    float sum = 0.0;

    for(int i = 0; i < n; i++)
        h[i] = priceof(characteristics[i], factors);


    for(int j = 0; j < c+1; j++){
        for(int i = 0; i < n; i++){
            sum += (h[i]-prices[i])*characteristics[i][j]*alpha/n;
        }

        factors[j] -= sum;
        sum = 0.0;
    }

}

int main() {
    int c, n;
    cin >> c >> n;
    vector<vector<float> > characteristics(n);
    vector<float> prices;
    vector<float> factors(c+1, 1.0);
    double pricemean;

    for(int i = 0; i < n; i++){
        float holder;
        for(int j = 0; j < c; j++){
            cin >> holder;
            characteristics[i].push_back(holder);
        }
        characteristics[i].push_back(1.0);
        cin >> holder;
        prices.push_back(holder);
        pricemean += holder;
    }

    //pricemean /= n;
    //factors[c] = pricemean;

    float cost = costfunc(characteristics, prices, factors, n, c);
    float costold = 0.0;
    float e = 0.001;


    while(abs(cost-costold) > e ){
        gradientdescent(characteristics, prices, factors, n, c, 0.1);
        costold = cost;
        cost = costfunc(characteristics, prices, factors, n, c);
    }

    int t;
    cin >> t;
    vector<float> target;

    for(int i = 0; i < t; i++){
        float holder;
        for(int j = 0; j < c; j++){
            cin >> holder;
            target.push_back(holder);
        }
        target.push_back(1.0);

        cout << priceof(target, factors) << endl;

        target.clear();
    }
    return 0;
}
