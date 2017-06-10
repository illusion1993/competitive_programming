#include <bits/stdc++.h>

using namespace std;

int n_cities, k_products, q_queries, kings_city, in1, in2;
int paths[10001][2];
bool traveled[10001] = {0};
int dist[10001] = {0};
int products[10001];

int gi[10001][10001];

/*
int find_distances(int city_number, int previous_distance) {
    traveled[city_number] = true;
    dist[city_number] = previous_distance + 1;

    for (int i = 0; i < n_cities - 1; i++) {
        if (paths[i][0] == city_number && !traveled[paths[i][1]]) {
            find_distances(paths[i][1], previous_distance + 1);
        }
        else if (paths[i][1] == city_number && !traveled[paths[i][0]]) {
            find_distances(paths[i][0], previous_distance + 1);
        }
    }
    return 0;
}

int clear_walk() {
    memset(traveled, 0, sizeof(traveled));
    return 0;
}

int find_gi(int from, int to) {
    //cout << "finding gi from " << from << " to " << to << endl;
    if (from == to) return dist[from];

    int child_gi = -1;
    traveled[from] = true;
    //cout << "marking " << from << " as traveled" << endl;
    for (int i = 0; i < n_cities - 1; i++) {
        //cout << "checking path " << paths[i].first << ", " << paths[i].second << endl;
        if (paths[i][0] == from && !traveled[paths[i][1]]) {
            //cout << "Need to go to " << paths[i].second << endl;
            child_gi = find_gi(paths[i][1], to);
        }
        else if (paths[i][1] == from && !traveled[paths[i][0]]) {
            //cout << "Need to go to " << paths[i].first << endl;
            child_gi = find_gi(paths[i][0], to);
        }

        if (child_gi != -1) break;
    }

    //cout << "gi from " << from << " to " << to << " is " << min(child_gi, dist[from]) << endl;

    return min(child_gi, dist[from]);
}
*/

vector<int> find_cities_with_product(int product) {
    vector<int> ans;
    for (int i = 0; i < n_cities; i++) {
        if (products[i] == product) ans.push_back(i + 1);
    }
    return ans;
}


vector<int> get_children(int city_number, int distance, int parent) {
    vector<vector<int> > children;
    vector<int> tmp;
    tmp.push_back(city_number);

    for (int i = 0; i < n_cities - 1; i++) {
        if (paths[i][0] == city_number && paths[i][1] != parent) {
            children.push_back(get_children(paths[i][1], distance + 1, city_number));
        }
        else if (paths[i][1] == city_number && paths[i][0] != parent) {
            children.push_back(get_children(paths[i][0], distance + 1, city_number));
        }
    }
    children.push_back(tmp);
    tmp.clear();

    for (int i = 0; i < children.size(); i++) {
        for (int j = 0; j < children[i].size(); j++) {
            tmp.push_back(children[i][j]);
            for (int k = 0; k < children.size(); k++) {
                if (k > i) {
                    for (int l = 0; l < children[k].size(); l++) {
                        gi[children[i][j]][children[k][l]] = distance;
                        gi[children[k][l]][children[i][j]] = distance;
                    }
                }
            }
        }
    }
    return tmp;
}


int find_max_gi_city(int from, int product) {
    int max_gi = INT_MIN, new_gi, city = -1;
    vector<int> cities;
    cities = find_cities_with_product(product);

    if (cities.size() == 1) return cities[0];

    for (int i = 0; i < cities.size(); i++) {
        //clear_walk();
        //new_gi = find_gi(from, cities[i]);
        new_gi = gi[from][cities[i]];
        if (new_gi > max_gi) {
            city = cities[i];
            max_gi = new_gi;
        }
    }
    return city;
}


int main () {
    cin >> n_cities >> k_products >> kings_city;
    for (int i = 0; i < n_cities - 1; i++) cin >> paths[i][0] >> paths[i][1];
    //find_distances(kings_city, -1);
    get_children(kings_city, 0, -1);
    for (int i = 0; i < n_cities; i++) cin >> products[i];
    cin >> q_queries;
    for (int i = 0; i < q_queries; i++) {
        cin >> in1 >> in2;
        cout << find_max_gi_city(in1, in2) << "\n";
    }

	return 0;
}
