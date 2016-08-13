#include<bits/stdc++.h>
using namespace std;

#define days 365
#define people 10

int main(){

    float division, available = days, probability = 1;

    for(int i = 0; i < people; i++){
        division = (available / days);

        probability *= division;

        available--;
    }

    probability = 1.0 - probability;

    cout << "There is a " << probability * 100.0 << "% chance that among a group of " << people << " people, at least 2 people have same birthday.";

	return 0;

}
