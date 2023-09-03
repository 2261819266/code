#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
int n,m,head[500010],cnt;
struct node
{
	int to,ne;
}e[1000010];
void add(int x,int y)
{
	e[++cnt].to=y;
	e[cnt].ne=head[x];
	head[x]=cnt;
}
ll ksm(int a,int b)
{
	ll res=1,base=a;
	while (b)
	{
		if (b%2) res=(res*base)%MOD;
		b>>=1;base=(base*base)%MOD;
	}
	return res;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	if (m==n-1)
	{
		ll ans=(n*ksm(2,m))%MOD;
		for (int i=1;i<=m;i++) ans=(ans+((m-i+1)*ksm(2,m-i))%MOD)%MOD;
		printf("%lld\n",ans);
		return 0;
	}
	if (m==n)
	{
		ll ans=(n*ksm(2,m))%MOD;
		for (int i=1;i<m;i++) ans=(ans+(m*ksm(2,m-i))%MOD)%MOD;
		ans=(ans+1)%MOD;
		printf("%lld\n",ans);
		return 0;
	}
	printf("%lld\n",ksm(2,n+m)-n*(m-1)/2);
}
