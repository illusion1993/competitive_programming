#include<bits/stdc++.h>

using namespace std;

vector<vector<int> >lines;
int msize;

void putLine(long long a, long long b, long long c){

    int m_found = 0;

    for(int i = 0; i < lines.size(); i++){

        if(a * lines[i][1] == b * lines[i][0]){

            m_found = 1;
            int found = 0;
            for(int j = 2; j < lines[i].size(); j++){
                if(lines[i][j] == c || b * lines[i][j] == c * lines[i][1])
                    found = 1;
            }
            if(!found){
                lines[i].push_back(c);
                int nsize = lines[i].size() - 2;
                msize = max(msize, nsize);
            }

            break;

        }

    }

    if(!m_found){
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);

        lines.push_back(v);

        msize = max(msize, 1);
    }

}

int main(){

    int t, n;
    long long a, b, c;

    cin >> t;

    while(t--){
        lines.clear();
        msize = 0;
        cin >> n;
        while(n--){
            cin >> a >> b >> c;

            putLine(a, b, c);

        }

        cout << msize << endl;

        //cout << "lines\n";
        //for(int i = 0; i < lines.size(); i++){
        //    for(int j = 0; j < lines[i].size(); j++){
        //        cout << lines[i][j] << " ";
        //    }
        //    cout << endl;
        //}

        //sort(lines.begin(), lines.end(), linesort);

        //cout << countMax() << endl;

    }


    return 0;

}
