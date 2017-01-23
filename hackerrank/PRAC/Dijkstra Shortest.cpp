#include <bits/stdc++.h>

using namespace std;

void traverse(int n, int curDis, vector< vector<int> > &paths , vector<int> &dis){

    if(curDis < dis[n]){
        dis[n] = curDis;

        for(int i = 0; i < paths[n].size(); i += 2){
            //cout << "calling for node " << paths[n][i] << " with distance " << curDis + paths[n][i + 1] << endl;
            traverse(paths[n][i], curDis + paths[n][i + 1], paths, dis);
        }
    }

}

int main(){

    int t, n, m, s;

    int from, to, weight;

    cin >> t;
    while(t--){

        cin >> n >> m;
        vector< vector<int> > paths(n);

        vector<int> v;
        for(int i = 0; i < n; i++) paths.push_back(v);

        while(m--){
            cin >> from >> to >> weight;
            paths[from - 1].push_back(to - 1);
            paths[from - 1].push_back(weight);
            paths[to - 1].push_back(from - 1);
            paths[to - 1].push_back(weight);
        }

        cin >> s;
        s--;

        vector<int> dis(n, INT_MAX);

        traverse(s, 0, paths, dis);
        /*
        cout << "paths are " << endl;
        for(int i = 0; i < paths.size(); i++){
            for(int j = 0; j < paths[i].size(); j++) cout << paths[i][j] << " ";
            cout << endl;
        }
        */

        for(int i = 1; i < dis.size(); i++) cout << dis[i] << " ";
        cout << endl;

    }


    return 0;
}
