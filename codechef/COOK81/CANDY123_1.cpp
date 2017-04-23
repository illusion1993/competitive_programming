#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int t, limak_capacity, bob_capacity, candy_plate, limak_eaten, bob_eaten;
    bool over;
    cin >> t;
    while(t--) {
        cin >> limak_capacity >> bob_capacity;
        over = false;
        candy_plate = 1;
        limak_eaten = bob_eaten = 0;
        
        while(!over) {
            if (limak_eaten + candy_plate > limak_capacity) {
                cout << "Bob\n";
                over = true;
            }
            else limak_eaten += candy_plate;
            candy_plate++;
            if (!over) {
                if (bob_eaten + candy_plate > bob_capacity) {
                    cout << "Limak\n";
                    over = true;
                }
                else bob_eaten += candy_plate;
            }
            candy_plate++;
        }

    }
    return 0;
}
