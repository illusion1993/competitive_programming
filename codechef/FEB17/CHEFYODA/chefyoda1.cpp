#include<bits/stdc++.h>
using namespace std;

# define MAX 1000000


/*  TLE
long long ncr(long long n, long long r) {
    if (n == r || r == 0) return 1;
    if (r == 1) return n;

    return ncr(n - 1, r) + ncr(n - 1, r - 1);
}
*/

/*  Number Overflow
long long ncr(int n, int r) {
    if (r > n / 2) r = n - r;
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}
*/

/*
//long long pascal_triangle[MAX + 1][MAX + 1];
map<pair<int, int>, long long> pascal_triangle;

void makePascalTriangle() {
    int i, j;

    //pascal_triangle[0][0] = 1;
    pascal_triangle[{0, 0}] = 1;

    for(i = 1; i < MAX; i++) {
        //pascal_triangle[i][0] = 1;
        pascal_triangle[{i, 0}] = 1;
        for(j = 1; j <= i; j++) {
            //pascal_triangle[i][j] = pascal_triangle[i - 1][j - 1] + pascal_triangle[i - 1][j];
            pascal_triangle[{i, j}] = pascal_triangle[{i - 1, j - 1}] + pascal_triangle[{i - 1, j}];
        }
    }
}

long long ncr(int n, int r) {
    //return pascal_triangle[n][r];
    return pascal_triangle[{n, r}];
}
*/

long ncr(int n, int r)
{
    long long ans=1;
    r = r > n - r ? n - r : r;
    int j = 1;
    for(;j<=r;j++,n--)
    {
        if(n%j==0)
        {
            ans*=n/j;
        }else
        if(ans%j==0)
        {
            ans=ans/j*n;
        }else
        {
            ans=(ans*n)/j;
        }
    }
    return ans;
}

map<pair<int, int>, double> ncrProbs;

double ncrProb(int n, int r) {
    vector<double> numerator;
    double main_prob = 0.0, prob;

    while(r <= n) {
        prob = 1.0;
        numerator.clear();
        //numerator.push_back(1);
        if (ncrProbs.count({n, r})) {
            prob = ncrProbs[{n, r}];
            //cout << "Prob found in store for " << n << ", " << r << endl;
        }
        else {
            for (int i = n; i >= 1; i--) {
                if (i > max(n - r, r)) numerator.push_back((double)i);
                else {
                    numerator.push_back((double)1);
                    if (i <= min(r, n - r)) {
                        //cout << "in denominator, " << i << " came" << endl;
                        int d = i, pos = 0, gcd;
                        /*
                        for (int j = numerator.size() - 1; j >= 0; j--) {
                            if ((int)numerator[j] % i == 0) {
                                numerator[j] /= i;
                                break;
                            }
                            //else cout << (int)numerator[j] << " is not divisible by " << i << endl;
                        }
                        */
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

            //cout << "For " << n << "C" << r << ", numerator remaining: ";
            //for (int i = 0; i < numerator.size(); i++) cout << numerator[i] << " ";
            //cout << endl;

            for (int i = 0; i < n; i++) {
                double multiplier = (double)numerator[i] / (double)2;
                prob *= multiplier;
                //cout << "For numerator " << (double)numerator[i] << " Multiplying prob with " << multiplier << ", it became " << prob << endl;
            }
            ncrProbs[{n, r}] = prob;
            ncrProbs[{n, n - r}] = prob;
            //cout << "Storing prob for " << n << ", " << r << " and " << n << ", " << n - r << endl;
        }
        main_prob += prob;
        //cout << "Prob for " << n << "C" << r << "is: " << prob << ", so far: " << main_prob << endl;
        //cout << "NCR value is " << ncr(n, r) << "/" << pow(2, n) << endl;
        r++;
    }

    return main_prob;
}


int main() {

    int n, m;
    cin >> n >> m;
    cout << fixed << std::setprecision(6) << ncrProb(m, n);
    return 0;

    /*
    int t, n, m;
    float prob, p, k;

    cin >> t;
    while(t--) {
        prob = 0;
        cin >> n >> m >> p >> k;

        if ((n % 2 == 0 && m % 2 == 0) || p == 0) {
            prob = 1.0;
        }
        else if (n % 2 == 1 && m % 2 == 1) {
            prob = 0.0;
        }
        else {
            for (int i = p; i <= k; i++) {
                long long tmp = ncr(k, i);
                prob += tmp;
            }
            for (int i = 0; i < k; i++) prob /= 2;
        }
        cout << fixed << std::setprecision(6) << prob << endl;
    }

    return 0;
    */
}
