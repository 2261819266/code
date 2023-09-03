#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
int n,m,u,v;
long long ans;
bool flag;
void f()
{
	long long x=2,y=1,z=n;
	while(z)
	{
		if(z&1)y*=x;
		z>>=1,x*=x,y%=mod,x%=mod;
	}
	ans=(y-1+mod)%mod;
	return ;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==n-1)flag=1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		if(u>v)swap(u,v);
		if((u!=i)||(v!=i+1))flag=0;
	}
	f(),printf("%lld",ans);
	return 0;
}
