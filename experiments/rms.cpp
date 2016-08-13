#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){

    double error = (109.85 * 109.85);
    error += (155.72 * 155.72);
    error += (137.66 * 137.66);
    error += (76.17 * 76.17);
    error += (139.75 * 139.75);
    error += (162.6 * 162.6);
    error += (151.77 * 151.77);

    error /= 7;
    error = sqrt(error);
    cout<<error;

    return 0;
}
