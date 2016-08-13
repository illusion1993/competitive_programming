#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > edges;
int info[1000][3], t, n, m, x, y, s;

void showDistances(){
    for(int i = 1; i <= n; i++){
        if(i != s) cout << info[i][1] << " ";
    }
}

void bfs(int node, int dist){

    info[node][2] = 1;

    for(int i = 0; i < edges[node].size(); i++){
        if(info[edges[node][i]][0] == 0){
            info[edges[node][i]][0] = 1;
            info[edges[node][i]][1] = dist + 6;
        }
    }

    for(int i = 0; i < edges[node].size(); i++){
        if(info[edges[node][i]][2] == 0) bfs(edges[node][i], dist+6);
    }

}

int main(){

    cin >> t;

    while(t--){

        cin >> n >> m;

        vector<int> e;

        for(int i = 0; i <= n; i++) edges.push_back(e);

        while(m--){
            cin >> x >> y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        cin >> s;

        for(int i = 1; i <= n; i++){
            if(i != s){
                info[i][0] = 0;
                info[i][1] = -1;
                info[i][2] = 0;
            }
        }

        bfs(s, 0);
        showDistances();

    }


    return 0;
}
