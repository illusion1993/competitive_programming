#include<bits/stdc++.h>

using namespace std;

vector<pair<float, float> >lines;

int isLine(float a, float c){

    for(int i = 0; i < lines.size(); i++){
        if(a == lines[i].first && c == lines[i].second)
            return 1;
    }

    return 0;

}

int linesort(pair<float, float> a, pair<float, float> b){

    return a.first > b.first;

}

int countMax(){

    if(!lines.size())
        return 0;

    else if(lines.size() == 1)
        return 1;

    int m = 1, count = 1;

    for(int i = 1; i < lines.size(); i++){
        if(lines[i].first == lines[i - 1].first){
            count++;
            m = max(m, count);
            //cout << lines[i].first << " is " << lines[i-1].first << endl;
        }
        else{
            //cout << lines[i].first << " is not " << lines[i-1].first << endl;
            count = 1;
            m = max(m, count);
        }
    }

    return m;

}

int main(){

    int t, n;
    float a, b, c;

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
