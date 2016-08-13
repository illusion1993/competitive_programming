#include <bits/stdc++.h>

using namespace std;

int main(){

    ifstream cin("A-large-practice.in");
    ofstream cout("out-large.txt");
   int n , c, i, p, p1, p2, num = 0;
   vector<int> val;

   cin >> n;
   while(n--){
        num++;
        val.clear();
        cin >> c >> i;
        while(i--){
            cin >> p;
            val.push_back(p);
        }

        for(i = 0; i < val.size(); i++){
            for(int j = 0; j < val.size(); j++){
                if(i != j && val[i] + val[j] == c){
                    p1 = min(i, j);
                    p2 = max(i, j);

                    goto found;
                }
            }
        }

        found: cout << "Case #" << num << ": " << p1+1 << " " << p2+1;
        if(n != 0) cout << endl;

   }

    return 0;

}
