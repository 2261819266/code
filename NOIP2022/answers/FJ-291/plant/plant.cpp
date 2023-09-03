#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
inline int read()
{
	int s=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())
		if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())
		s=s*10+c-'0';
	return s*f;
}
inline int rd()
{
	char c=getchar();
	for(;!isdigit(c);c=getchar());
	return c-'0';
}
int t,id;
int n,m,C,F,a[1005][1005];
int f[1005][1005],g[1005][1005];
void init()
{
	memset(g,0,sizeof(g));
	for(int i=1;i<=n;i++)
	{
		int lst=-1;
		for(int j=m;j>=1;j--)
		{
			if(lst==-1&&a[i][j]==0)lst=j;
			if(a[i][j]==1)f[i][j]=0,lst=-1;
			else f[i][j]=lst-j+1;
		}
		for(int j=1;j<=m;j++)
		{
			if(a[i][j])continue;
			g[i][j]=g[i-1][j]+f[i][j]-1;
		}
	}
}
ll ans1,ans2;
ll cnt[1005][1005],sum[1005][1005];
void solve()
{
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!a[i][j]&&!a[i-1][j])
			{
				cnt[i][j]=1ll*(f[i][j]-1)*(g[i-2][j])%mod;
				ans1=(ans1+cnt[i][j])%mod;
			}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			if(a[j][i])sum[j][i]=0;
			else sum[j][i]=sum[j-1][i]+cnt[j][i];
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(a[i][j])continue;
			ans2=(ans2+sum[i-1][j])%mod;
		}
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	t=read(),id=read();
	while(t--)
	{
		n=read(),m=read(),C=read(),F=read();
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				a[i][j]=rd();
		init();
		solve();
		printf("%lld %lld\n",ans1*C%mod,ans2*F%mod);
		ans1=ans2=0;
	}
	return 0;
}
