#include<bits/stdc++.h>
using namespace std;
long long n,m;
int from[200001],to[200001],cnt,head[50001],nxt[200001];
long long f[1001][1001],g[500001];
long long po[100001],ans;
int mod=1e9+7;
void add(int u,int v)
{
	to[++cnt]=v;
	from[cnt]=u;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
void pre()
{
	po[0]=1;
	for(int i=1;i<=m;i++)
	{
		po[i]=(po[i-1]*2)%mod;
	}
	for(int i=1;i<=n;i++)
	f[1][i]=1,f[0][i]=1;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	int v,u;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	pre();
	ans=(ans+n*po[m])%mod;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=head[j];k;k=nxt[k])
			{
				if(to[k]>j)
	     		f[i][j]=(f[i][j]+f[i-1][to[k]])%mod;
			}
			g[i]=(g[i]+f[i][j])%mod;
		}
		ans=(ans+g[i]*po[m-i+1])%mod;
	}
	cout<<ans<<'\n';
	return 0;
}
