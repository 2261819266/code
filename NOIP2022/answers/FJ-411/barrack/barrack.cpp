#include<bits/stdc++.h>
#define int long long
const int Mod=1e9+7;
using namespace std;
int n,m,ans;
int qpow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1) 
		{
			res=(res*x)%Mod;
		}
		x=x*x%Mod;
		y>>=1;
	}
	return res;
}
signed main()
{
   freopen("barrack.in","r",stdin);
   freopen("barrack.out","w",stdout);
   cin>>n>>m;
   ans=qpow(2,n)-1;
   cout<<ans<<endl;
   return 0;
}


