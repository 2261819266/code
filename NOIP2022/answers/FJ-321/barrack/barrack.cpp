#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010],n,m,mod=1000000007,u,v,ans;
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=m;i++)
	{
		scanf("%lld%lld",&u,&v);
	}
	a[0]=a[n]=1;
	for(long long i=1;i<=n/2;i++)
	{
		a[n-i]=a[i]=a[i-1]*(n-i+1)/i%mod;
	}
	b[0]=b[m]=1;
	for(long long i=1;i<=m/2;i++)
	{
		b[m-i]=b[i]=b[i-1]*(m-i+1)/i%mod;
	}
	for(long long i=0;i<=m;i++)
	{
		ans=(ans+(n*b[i])%mod)%mod;
	}
	for(long long i=2;i<=n;i++)
	{
		ans=(ans+a[i])%mod;
	}
	printf("%lld",ans);
	return 0;
}
