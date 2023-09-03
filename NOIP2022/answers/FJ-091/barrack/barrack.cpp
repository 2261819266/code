#include<cstdio>
#include<iostream>
using namespace std;
const int p=1e9+7;
int n,m,a,b,low[500005],dfn[500005],fdfn[500005],fa[500005];
long long opt[500005][2];
struct node
{
	int v;
	int next;
}edge[2000006],e[2000006];
int h[500005],cnt=1,cont,head[500005];
int vis[500005],dl[500005],tree[500005];
void Add(int u,int v)
{
	cont++;
	e[cont].v=v;
	e[cont].next=head[u];
	head[u]=cont;
}
void Addedge(int u,int v)
{
	cnt++;
	edge[cnt].v=v;
	edge[cnt].next=h[u];
	h[u]=cnt;
}
void addedge(int u,int v)
{
	Addedge(u,v);
	Addedge(v,u);
}
int sum;
void tar(int u,int it)
{
	low[u]=dfn[u]=++sum;
	fdfn[sum]=u;
	for(int i=h[u];i;i=edge[i].next)
	{
		int v=edge[i].v;
		if(v==edge[it^1].v)
		{
			continue ;
		}
		if(dfn[v]==0)
		{
			tar(v,i);
			low[u]=min(low[u],low[v]);
		}
		else 
		{
			low[u]=min(low[u],dfn[v]);
		}
	}
}
int find(int x)
{
	if(dfn[x]==low[x])return low[x];
	else return low[x]=find(fdfn[low[x]]);
}
long long ksm(long long  a,long long b)
{
	long long c=1;
	while(b)
	{
		if(b%2==1)
		{
			c*=a;
			c%=p;
		}
		a=(a*a)%p;
		b/=2;
	}
	return c;
}
void dfs(int u)
{
	tree[u]=dl[u];
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(v==fa[u])continue;
		fa[v]=u;
		dfs(v);
		tree[u]=tree[u]+1+tree[v];
	}
}
void dp(int u)
{
	opt[u][0]=ksm(2,vis[u]+dl[u])%p;
	opt[u][1]=ksm(2,dl[u])%p;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(v==fa[u])continue;
		dp(v);
		opt[u][0]=opt[u][0]*((opt[v][0]+opt[v][1]*2)%p)%p;
		opt[u][1]=opt[u][1]*opt[v][1]*2%p;
	}
	opt[u][0]=(opt[u][0]+p-opt[u][1])%p;
}
void dpbc(int u)
{
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(v==fa[u])continue;
		dpbc(v);
		opt[1][0]=(opt[1][0]+(ksm(2,tree[u]-tree[v]-1)%p*opt[v][0]))%p;
	}
}
int main()
{
	freopen("barrack","r",stdin);
	freopen("barrack","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		addedge(a,b);
	}
	tar(1,0);
	for(int i=1;i<=n;i++)find(i);
	for(int i=1;i<=n;i++)
	{
		vis[low[i]]++;
		for(int j=h[i];j;j=edge[j].next)
		{
			int v=edge[j].v;
			if(low[v]!=low[i])
			{
				Add(low[i],low[v]);
			}
			else dl[low[i]]++;
		}
	}
	for(int i=1;i<=n;i++)dl[i]/=2;
	dfs(1);
	dp(1);
	dpbc(1);
	printf("%lld",opt[1][0]);
	return 0;
}
