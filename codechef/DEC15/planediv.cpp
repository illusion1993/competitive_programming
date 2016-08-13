#include<bits/stdc++.h>

using namespace std;

vector<vector<int> >lines;

int isLine(long long a, long long b, long long c){

    for(int i = 0; i < lines.size(); i++){

        if(a * lines[i][1] == b * lines[i][0]){

            int found = 0;
            for(int j = 2; j < lines[i].size(); j++){
                if(lines[i][j] == c)
                    found = 1;
            }
            if(!found)
                lines[i].push_back(c);

            break;

        }

    }

    return -1;

}

int linesort(pair<float, float> a, pair<float, float> b){

    return a.first > b.first;

}

int main(){

    int t, n;
    long long a, b, c;

    cin >> t;

    while(t--){
        cin >> n;
        while(n--){
            cin >> a >> b >> c;

            a = atan(-a/b);
            if(b != 0){
                c = -c/b;
            }
            else{
                c *= -1;
            }

            if(!isLine(a, c))
                lines.push_back(make_pair(a, c));

        }

        sort(lines.begin(), lines.end(), linesort);

        cout << countMax() << endl;

    }


    return 0;

}
