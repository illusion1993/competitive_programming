#include<iostream>

using namespace std;

int count(int i, int j){

    if(i == j) return 1;

    else{
        if(i > j)
            return 1 + count(i - j, j);

        else
            return 1 + count(i, j - i);
    }

}

int calc(int m,int n,int p,int q)
{

	int ans = 0;

	for(int i = m; i <= n; i++){
        for(int j = p; j <= q; j++){
            ans += count(i, j);
        }
	}

	return ans;

}

int main(){

    cout << calc(2, 5, 3, 7);

    return 0;

}
