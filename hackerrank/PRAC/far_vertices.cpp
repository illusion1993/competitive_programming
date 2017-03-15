#include <bits/stdc++.h>
using namespace std;

int n, k, dist[101][101], min_marked = INT_MAX;
map<int, vector<int> > children;
vector<pair<int, pair<int, int> > > distpair;

vector<int> distant;
map<int, bool> is_distant;

vector<pair<int, int> > give_dist(int root, int parent) {
    //cout << "called at root " << root << " from parent " << parent << endl;
    vector<pair<int, int> > ans, tmp;
    int s;

    ans.push_back({root, 0});
    if (!(children[root].size() == 1 && children[root][0] == parent)) {
        for (int i = 0; i < children[root].size(); i++) {
            if (children[root][i] != parent) {
                tmp = give_dist(children[root][i], root);
                s = ans.size();

                //cout << root << " processing data from " << children[root][i] << "\n";
                for (int j = 0; j < tmp.size(); j++) {
                    tmp[j].second++;
                    for (int k = 0; k < s; k++) {
                        dist[tmp[j].first][ans[k].first] = tmp[j].second + ans[k].second;
                        dist[ans[k].first][tmp[j].first] = tmp[j].second + ans[k].second;
                        distpair.push_back({tmp[j].second + ans[k].second, {min(ans[k].first, tmp[j].first), max(ans[k].first, tmp[j].first)}});
                        //cout << "Making dist[" << tmp[j].first << "][" << ans[k].first << "] = " << tmp[j].second + ans[k].second << endl;
                    }
                    ans.push_back(tmp[j]);
                }
            }
        }
    }
    /*cout << "for call at root " << root << " from parent " << parent << ", ans is \n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << ": " << ans[i].second << endl;
    }*/
    return ans;
}

void find_distant() {
    for (int i = distpair.size() - 1; i >= 0; i--) {
        if (distpair[i].first > k) {
            if (!is_distant[distpair[i].second.first]) {
                is_distant[distpair[i].second.first] = true;
                distant.push_back(distpair[i].second.first);
            }
            if (!is_distant[distpair[i].second.second]) {
                is_distant[distpair[i].second.second] = true;
                distant.push_back(distpair[i].second.second);
            }
        }
        else break;
    }
}

void make_min_marked(map<int, bool> marked_so_far) {

    int distmax = INT_MIN, i = distpair.size() - 1, no_marked = 0;
    cout << "One marking scheme: ";
    for (int i = 1; i <= n; i++) if (marked_so_far[i]) {
        cout << i << " ";
        no_marked++;
    }
    cout << endl;

    while(distpair[i].first > k && i >= 0) {
        if (!marked_so_far[distpair[i].second.first] && !marked_so_far[distpair[i].second.second]) {
            distmax = max(distmax, distpair[i].first);
            cout << "one remaining distance " << distpair[i].first << endl;
        }
        i--;
    }
    if (distmax <= k) {
        min_marked = min(min_marked, no_marked);
        cout << "Marking scheme succeeded, marked vertices: " << no_marked << endl;
    }
}

void find_min_marked(int index, map<int, bool> marked_so_far) {
    if (index == distant.size()) {
        make_min_marked(marked_so_far);
    }
    else {
        find_min_marked(index + 1, marked_so_far);
        marked_so_far[distant[index]] = true;
        find_min_marked(index + 1, marked_so_far);
    }
}

int main() {
    int in1, in2;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        cin >> in1 >> in2;
        if (children.count(in1)) {
            children[in1].push_back(in2);
        }
        else {
            vector<int> v;
            v.push_back(in2);
            children[in1] = v;
        }
        if (children.count(in2)) {
            children[in2].push_back(in1);
        }
        else {
            vector<int> v;
            v.push_back(in1);
            children[in2] = v;
        }
    }
    give_dist(1, 0);
    sort(distpair.begin(), distpair.end());
    find_distant();
    map<int, bool> marked_so_far;
    find_min_marked(0, marked_so_far);
    cout << min_marked << "------------------ans";

    /*cout << "Dist are: \n";
    for (int i = 0; i < distpair.size(); i++) {
        cout << distpair[i].second.first << " - " << distpair[i].second.second << ": " << distpair[i].first << endl;
    }*/

    cout << "distant vertices are: ";
    for (int i = 0; i < distant.size(); i++) cout << distant[i] << " ";
    cout << endl;

    return 0;
}
