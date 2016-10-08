#include<iostream>
#include<string>
using namespace std;
int main(){
	int t;
	cin>>t;
	string str;
	while(t--){
		cin>>str;
		long long ans=1;
		int len=str.length();
		for(int i=0;i<len;i++){
			if(i%2==0&&str[i]=='l'){
				ans=(ans*2)%1000000007;
			}
			else if(i%2==0&&str[i]=='r'){
				ans=(ans*2+2)%1000000007;
			}
			else if(i%2==1&&str[i]=='l'){
				ans=(ans*2-1)%1000000007;
			}
			else if(i%2==1&&str[i]=='r'){
				ans=(ans*2+1)%1000000007;
			}
		}
		cout<<(ans%1000000007)<<endl;
	}
	return 0;
} 