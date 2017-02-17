#include<bits/stdc++.h>
using namespace std;

#define MAX_NUMBER 1000000000000000

map<pair<int, int>, double> ncrProbs;

double firstNcrProb(int n, int r) {
    if (n == 1) return 0.5;
    vector<double> numerator;
    double prob = 1.0;

    for (int i = n; i >= 2; i--) {
        if (i > max(n - r, r)) {    // This number is in numerator
            if (numerator.size() == 0 || numerator[numerator.size() - 1] * (double)i > MAX_NUMBER) {
                numerator.push_back((double)i);
                //cout << "Pushing " << i << " into numerator as new number" << endl;
            }
            else {
                numerator[numerator.size() - 1] *= (double)i;
                //cout << "Multiplying " << i << " into last elem of numerator, making it " << numerator[numerator.size() - 1] << endl;
            }
        }

        else if (i <= min(r, n - r)) {

            int pos = 0;
            double max_nume;
            max_nume = numerator[0];
            for (int x = 0; x < numerator.size(); x++) {
                if (numerator[x] > max_nume) {
                    max_nume = numerator[x];
                    pos = x;
                }
            }
            //cout << "Dividing numerator pos " << pos << ": " << numerator[pos] << " from numerator by " << i << ", it became ";
            numerator[pos] /= (double)i;
            //cout << numerator[pos] << "\n";
            /*
            while(d != 1) {
                gcd = __gcd((int)numerator[pos], d);
                if (gcd != 1) {
                    cout << "Dividing " << numerator[pos] << " from numerator & " << d << " from denmtr by " << gcd << endl;
                    numerator[pos] /= gcd;
                    d /= gcd;
                }
                pos++;
            }
            */
        }
    }

    /*
    cout << "For " << n << "C" << r << ", numerator remaining: ";
    for (int i = 0; i < numerator.size(); i++) cout << numerator[i] << " | ";
    cout << endl;
    */

    int divisions = n, pos = 0;
    while(divisions && pos < numerator.size()) {
        while(numerator[pos] >= 1 && divisions) {
            numerator[pos] /= (double)2;
            divisions--;
        }
        pos++;
    }

    /*
    cout << "After" << n - divisions << " 2 divisions, numerator remaining: ";
    for (int i = 0; i < numerator.size(); i++) cout << numerator[i] << " ";
    cout << endl;
    */

    for (int i = 0; i < numerator.size(); i++) {
        prob *= numerator[i];
        if (divisions) {
            prob /= (double)2;
            divisions--;
        }
    }
    //ncrProbs[{n, r}] = prob;
    ncrProbs[{n, n - r}] = prob;
    return prob;
}

double ncrProb(int n, int r) {
    double total_prob, prob;
    total_prob = prob = firstNcrProb(n, r);

    //cout << "First prob for " << n << "C" << r << " is: " << prob << endl;

    for (int i = r + 1; i <= n; i++) {
        // prob = ncr prob of nCi and add in total_prob
        if (ncrProbs.count({n, i})) {
            prob = ncrProbs[{n, i}];
            //cout << "Found in store: ";
        }
        else {
            // compute by recurrence
            prob *= (n - i + 1);
            prob /= i;
            //ncrProbs[{n, i}] = prob;
            ncrProbs[{n, n - i}] = prob;
        }

        //cout << "ncrProb(" << n << ", " << i << "): " << prob << " --- ";
        total_prob += prob;
    }
    //cout << endl;

    return total_prob;

}

int main() {

    //cout << LLONG_MAX << endl << ULLONG_MAX << endl;

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
