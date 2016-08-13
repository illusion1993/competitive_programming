#include<bits/stdc++.h>
using namespace std;

int n, q, p, in_ring;

vector<int> powers;
vector<int> fights;
vector<int> round_winner;

int make_fight(int round_number, int new_fighter_index){
	int winner = (powers[round_winner[round_number]] > powers[new_fighter_index]) ? round_winner[round_number] : new_fighter_index;
	fights[round_winner[round_number]]++;
	fights[new_fighter_index]++;
	round_winner[round_number] = -1;
	if(round_winner.size() - 1 == round_number){
		round_winner.push_back(winner);
	}
	else if(round_winner[round_number + 1] == -1){
		round_winner[round_number + 1] = winner;
	}
	else{
		make_fight(round_number + 1, winner);
	}
	return 0;
};

int main(){
	cin >> n >> q;
	round_winner.push_back(-1);
	in_ring = 0;
	for(int i = 0; i < n; i++){
		cin >> p;
		powers.push_back(p);
		fights.push_back(0);
		if(!in_ring){
			in_ring = 1;
		}
		else{
			in_ring = 0;
			int winner = (powers[i-1] > p) ? i-1 : i;
			fights[i]++;
			fights[i-1]++;
			if(round_winner[0] == -1){
				round_winner[0] = winner;
			}
			else{
				make_fight(0, winner);
			}
		}
	}
	if(in_ring){
		int i = 0;
		while(round_winner[i] == -1){
			i++;
		}
		if(round_winner[i] != -1){
			make_fight(i, n - 1);
		}
	}
	for(int i = 0; i < q; i++){
		cin >> p;
		cout << fights[p-1] << endl;
	}
	return 0;
}
