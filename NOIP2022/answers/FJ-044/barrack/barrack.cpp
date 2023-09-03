#include<cstdio>
#include<iostream>
#define re register
using namespace std;
const long long mod=1e9+7;
const int N=5e5+5;
const int M=1e6+5;
int n,m;
int he[N],nex[M<<1],to[M<<1],tot=0;
inline void add(int u,int v)
{
	tot++;
	nex[tot]=he[u];
	he[u]=tot;
	to[tot]=v;
}
inline long long Power(int base,int power)
{
	long long result=1;
	while(power)
	{
		if(power&1) result=result*base%mod;
		power=power>>1;
		base=base*base%mod;
	}
	return result;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	long long ans=0;
	for(re int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(re int i=0;i<n;i++)
		ans=(ans+((n-i)*Power(2,m-i))%mod)%mod;
	printf("%lld",ans);
	return 0;
}
