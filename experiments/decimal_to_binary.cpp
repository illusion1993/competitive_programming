#include <bits/stdc++.h>

using namespace std;

//int powers_of_two[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

int decimal_to_binary_via_division(int n) {
    while (n) {
        n /= 2;
    }
    return 0;
}

int decimal_to_binary_via_subtraction(int n) {
    int level = -1, subtractand = 1;
    while (n > subtractand) {
        level++;
        n -= subtractand;
        subtractand *= 2;
    }
    /*
    for (int i = 0; i < level + 1; i++) {
        cout << "1";
    }
    cout << " + ";
    */
    if (n > 1) decimal_to_binary_via_subtraction(n);
    /*
    else cout << n << endl;
    */
    return 0;
}

int main() {

    int n, start_s, stop_s;

    for (int i = 0; i < 10; i++) {
        start_s=clock();
        for (int j = 1; j <= 100000; j++) {
            decimal_to_binary_via_subtraction(j);
        }
        stop_s=clock();
        cout << "Test "<< i + 1 << " time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    }

    for (int i = 0; i < 10; i++) {
        start_s=clock();
        for (int j = 1; j <= 100000; j++) {
            decimal_to_binary_via_division(j);
        }
        stop_s=clock();
        cout << "Test "<< i + 1 << " time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    }

    return 0;
}
