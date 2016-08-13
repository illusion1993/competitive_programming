#include <iostream>
using namespace std;
#define max 2005
#include<cstring>
#include<cstdio>
#define MOD 1000000000
int t,v[max],ans[max],i,j,n,m;
int main()
{
	// your code goes here

	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		v[0]=1;
		for(i=1;i<=m;++i)
			for(j=1;j<=m;++j)
				v[j]=(v[j]+v[j-1])%MOD;
		for(i=0;i<=n;++i)
			ans[i]=1;
		for(i=1;i<=m;++i)
			for(j=1;j<=n;++j)
				ans[j]=(ans[j]+1ll*ans[j-1]*v[i])%MOD;

		cout<<ans[n]<<endl;
		memset(v,0,(m+1)*sizeof(int));
		memset(ans,0,(n+1)*sizeof(int));
	}
	return 0;
}
