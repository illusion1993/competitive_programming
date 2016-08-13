#include <iostream>
using namespace std;

int main() {
    int t,x1,x2,y1,y2;
    cin>>t;
    while(t--){
        cin>>x1>>y1>>x2>>y2;
        cout<<x2+(x2-x1)<<" "<<y2+(y2-y1)<<endl;
    }
    return 0;
}
