#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct polygon{
    int v, max_x, max_done, index, inside;
    vector<int> x;
};

bool sortMax_x(const polygon &a, const polygon &b)
{
    return a.max_x < b.max_x;
}

bool sortIndex(const polygon &a, const polygon &b)
{
    return a.index < b.index;
}

int main(){

    int t, n, m, x, y;
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin>>t;

    while(t--){
        vector<polygon> polygons;
        cin>>n;

        for(int i=0; i<n; i++){
            polygon p;
            p.max_done=0;
            p.index=i;

            cin>>m;
            p.v = m;

            while(m--){
                cin>>x>>y;
                p.x.push_back(x);
                if( (p.max_done==0) || (p.max_done==1 && p.max_x<x) ){
                    p.max_x=x;
                    p.max_done=1;
                }
            }

            polygons.push_back(p);
        }

        sort(polygons.begin(), polygons.end(), sortMax_x);

        for(int i=0; i<polygons.size(); i++) polygons[i].inside = i;

        sort(polygons.begin(), polygons.end(), sortIndex);

        for(int i=0; i<polygons.size(); i++) cout<<polygons[i].inside<<" ";

    }

    return 0;
}
