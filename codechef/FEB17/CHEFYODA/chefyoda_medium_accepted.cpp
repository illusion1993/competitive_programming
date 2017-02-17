#include<bits/stdc++.h>
using namespace std;

map<pair<int, int>, double> ncrProbs;

double firstNcrProb(int n, int r) {
    if (n == 1) return 0.5;
    vector<double> numerator;
    double prob = 1.0;

    for (int i = n; i >= 1; i--) {
        if (i > max(n - r, r)) numerator.push_back((double)i);

        else {
            numerator.push_back((double)1);
            if (i <= min(r, n - r)) {
                int d = i, pos = 0, gcd;
                while(d != 1) {
                    gcd = __gcd((int)numerator[pos], d);
                    if (gcd != 1) {
                        numerator[pos] /= gcd;
                        d /= gcd;
                    }
                    pos++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        double multiplier = (double)numerator[i] / (double)2;
        prob *= multiplier;
    }

    ncrProbs[{n, r}] = prob;
    ncrProbs[{n, n - r}] = prob;
    return prob;
}

double ncrProb(int n, int r) {

    double total_prob, prob;
    total_prob = prob = firstNcrProb(n, r);

    for (int i = r + 1; i <= n; i++) {
        if (ncrProbs.count({n, i})) {
            prob = ncrProbs[{n, i}];
        }
        else {
            prob *= (n - i + 1);
            prob /= i;
            ncrProbs[{n, i}] = prob;
            ncrProbs[{n, n - i}] = prob;
        }
        total_prob += prob;
    }

    return total_prob;

}

int main() {

    int t, n, m, p, k;
    double prob;

    cin >> t;
    while(t--) {
        cin >> n >> m >> p >> k;

        if ((n % 2 == 0 && m % 2 == 0) || p == 0) {
            prob = 1.0;
        }
        else if (n % 2 == 1 && m % 2 == 1) {
            prob = 0.0;
        }
        else {
            prob = ncrProb(k, p);
        }
        cout << fixed << std::setprecision(6) << prob << endl;
    }

    return 0;
}
