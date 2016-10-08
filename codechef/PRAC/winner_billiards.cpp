#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n][2];
	int lead=0, winner=0;
	for(int i=0; i<n; i++){
		cin>>arr[i][0];
		cin>>arr[i][1];
		if(arr[i][0]>arr[i][1] && arr[i][0]-arr[i][1]>lead){
			winner=1;
			lead=arr[i][0]-arr[i][1];
		}
		else if(arr[i][1]>arr[i][0] && arr[i][1]-arr[i][0]>lead){
			winner=2;
			lead=arr[i][1]-arr[i][0];
		}
	}
	cout<<winner<<" "<<lead;
	return 0;
}
