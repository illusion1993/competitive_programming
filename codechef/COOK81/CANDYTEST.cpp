#include<bits/stdc++.h>
using namespace std;

string sol1(int a, int b) {
	int c;
    bool over, a_lose, b_lose;
    c = 1;
    over = a_lose = b_lose = false;
    while(!over) {
        if (a >= c) {
            a -= c;
            c++;
        }
        else {
            over = true;
            a_lose = true;
        }
        if (!over) {
            if (b >= c) {
                b -= c;
                c++;
            }
            else {
                over = true;
                b_lose = true;
            }
        }
    }
    return ((a_lose) ? "BOB" : "LIMAK");
}

string sol2(int limak_capacity, int bob_capacity) {
	int candy_plate, limak_eaten, bob_eaten;
    bool over;
    over = false;
    candy_plate = 1;
    limak_eaten = bob_eaten = 0;
    
    while(!over) {
        if (limak_eaten + candy_plate > limak_capacity) {
            return "BOB";
            over = true;
        }
        else limak_eaten += candy_plate;
        candy_plate++;
        if (!over) {
            if (bob_eaten + candy_plate > bob_capacity) {
                return "LIMAK";
                over = true;
            }
            else bob_eaten += candy_plate;
        }
        candy_plate++;
    }
    return "";
}


int main(int argc, char const *argv[])
{
	string s1, s2;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			s1 = sol1(i, j);
			s2 = sol2(i, j);

			if (s1 != s2) {
				cout << i << " - " << j << ": " << s1 << ", " << s2 << endl;
			}
		}
	}
	return 0;
}