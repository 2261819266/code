#include<bits/stdc++.h>
using namespace std;
int read()
{
	char c=getchar();int x=0,f=1;
	while(c>'9'||c<'0'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
#define ll long long
const int mod=1e9+7,N=5e5+10,M=2e6+10;
int n,m,ans,tot[N],f[N],power[M],dfn[N],low[N],T,stak[N],top,col[N],colcnt,node[N],edge[N];
struct point
{
	int head[N],from[M],to[M],cnt;
	void add(int x,int y)
	{
		from[++cnt]=head[x];
		head[x]=cnt;
		to[cnt]=y;
		return;
	}
}G,tree;
void Tarjan(int x,int pre)
{
	dfn[x]=low[x]=++T;stak[++top]=x;
	for(int i=G.head[x];i;i=G.from[i])
	{
		if(i==(pre^1))continue;
		int v=G.to[i];
		if(!dfn[v])
		{
			Tarjan(v,i);
			low[x]=min(low[x],low[v]);
		}
		else if(!col[v])
			low[x]=min(low[x],dfn[v]);
	}
	if(low[x]==dfn[x])
	{
		col[x]=++colcnt;node[colcnt]=1;
		while(stak[top]!=x)
		{
			col[stak[top]]=col[x];
			node[colcnt]++;
			top--;
		}
		top--;
	}
	return;
}
void dfs(int x,int y)
{
	tot[x]=edge[x];int sum=1;
	for(int i=tree.head[x];i;i=tree.from[i])
	{
		int v=tree.to[i];
		if(v==y)continue;
		dfs(v,x);
		tot[x]+=tot[v]+1;
		sum=((ll)power[tot[v]+1]+f[v])%mod*sum%mod;
	}
	f[x]=(ll)power[edge[x]]*(power[node[x]]+mod-1)%mod*sum%mod;
	sum=(sum-power[tot[x]-edge[x]]+mod)%mod;
	f[x]=((ll)power[edge[x]]*sum+f[x])%mod;
	if(m>tot[x])ans=((ll)f[x]*power[m-tot[x]-1]+ans)%mod;
	else ans=(f[x]+ans)%mod;
	return;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();G.cnt=power[0]=1;
	for(int i=1;i<=m;i++)
		power[i]=(ll)power[i-1]*2%mod;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		G.add(u,v);G.add(v,u);
	}
	Tarjan(1,0);
	for(int i=1;i<=n;i++)
		for(int j=G.head[i];j;j=G.from[j])
		{
			int u=G.to[j];
			if(col[i]==col[u])
				edge[col[i]]++;
			else tree.add(col[i],col[u]);
		}
	for(int i=1;i<=colcnt;i++)
		edge[i]/=2;
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
