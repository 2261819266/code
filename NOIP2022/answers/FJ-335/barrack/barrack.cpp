#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,m,ans1,ans2;
int qpow(int x,int y)
{
	int t=1;
	while(y)
	{
		if(y&1)t=t*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return t;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		//add(u,v);
		//add(v,u);
	}
	if(m==n-1)
	{
		ans1=qpow(2,m)*n%mod;
		ans2=qpow(2,m-1)*n%mod*(n-1)%mod/2;
		printf("%d\n",(ans1+ans2)%mod);
	}
	else printf("%d\n",(n+1)%mod*(n-1)%mod*m%mod*m%mod);
	return 0;
}
