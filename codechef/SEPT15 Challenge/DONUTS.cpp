#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){

    int t, n, m, a, ones = 0, links, cuts;
    cin >> t;

    while(t--){

        cin >> n >> m;
        links = m-1;
        ones = 0;
        cuts = 0;

        while(m--){
            cin >> a;
            if(a == 1) ones ++;
        }

        if(links >= (2*ones)){
            links -= 2*ones;
            cuts += ones;
            cuts += links;
        }
        else if(links < (2*ones)){
            cuts = links / 2;
            links = links % 2;
            cuts += links;
        }

        cout << cuts << endl;

    }



    return 0;

}
