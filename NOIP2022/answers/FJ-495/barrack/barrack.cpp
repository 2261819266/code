#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,head1[500005],low[500005],dfn[500005],col[500005],Tim,tot1,tot2;
ll ans,mod=1e9+7,num1[500005],num2[500005],f[500005][2],cnt1;
bool p[2000005];
vector<int>e[500005];
struct edge1
{
	int from,to,nxt;
}
b1[2000005];
void add1(int u,int v)
{
	b1[++tot1].to=v;
	b1[tot1].from=u;
	b1[tot1].nxt=head1[u];
	head1[u]=tot1;
	return ;
}
void yyz(int x,int fa)
{
	dfn[x]=low[x]=++Tim;
	for(int i=head1[x],v;i;i=b1[i].nxt)
	{
		v=b1[i].to;
		if(v==fa)
			continue;
		if(!dfn[v])
		{
			yyz(v,x);
			if(dfn[x]==1&&low[v]>1||dfn[x]!=1&&low[v]==dfn[v])
				p[i]=1;
			low[x]=min(low[x],low[v]);
		}
		else
			low[x]=min(low[x],low[v]);
	}
}
void hyx(int x,int fa)
{
	if(col[x])
		return ;
	col[x]=tot2;
	for(int i=head1[x];i;i=b1[i].nxt)
		if(!p[i]&&b1[i].to!=fa)
			hyx(b1[i].to,x);
}
ll power(ll x,ll y)
{
	if(!y)
		return 1;
	ll z=power(x,y/2);
	z=(z*z)%mod;
	if(y&1)
		return (z*x)%mod;
	return z;
}
void dfs(int x,int fa)
{
	f[x][1]=(num1[x]-1)*num2[x]%mod;
	f[x][0]=num2[x];
	ll sum=0;
	for(int i=0,v;i<e[x].size();i++)
	{
		v=e[x][i];
		if(v==fa)
			continue;
		dfs(v,x);
		f[x][1]=(f[x][1]+(num1[x])*num2[x]*(f[v][0]+f[v][1]))%mod;
		f[x][0]=(f[x][0]+f[v][0])%mod;
		sum=(sum+f[v][1])%mod;
	}
	ans=(ans+f[x][1])%mod;
	ans=(ans+sum/2)%mod;
	return ;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++)
		scanf("%d%d",&x,&y),add1(x,y),add1(y,x);
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			yyz(i,-1);
	for(int i=1;i<=n;i++)
		if(!col[i])
			tot2++,hyx(i,-1);
	for(int i=1;i<=n;i++)
		num1[col[i]]++;
	for(int i=1;i<=tot1;i+=2)
		if(!p[i])
			num2[col[b1[i].from]]++;
		else
			cnt1++;
	for(int i=1,u,v;i<=n;i++)
	{
		u=col[i];
		for(int j=head1[i];j;j=b1[j].nxt)
		{
			v=col[b1[j].to];
			if(u!=v)
				e[u].push_back(v);
		}
	}
	for(int i=1;i<=tot2;i++)
		num1[i]=power(2,num1[i]);
	for(int i=1;i<=tot2;i++)
		num2[i]=power(2,num2[i]);
	dfs(1,-1);
	printf("%lld",(ans-1+mod)%mod);
	return 0;
}
