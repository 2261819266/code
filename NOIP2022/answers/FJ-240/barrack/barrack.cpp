#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=5e5+5,M=1e6+5;
int n,m;
struct node
{
	int u,v;
	int book;
}e[M];int cnt;
int g[N];
int fa[N];
int Find(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=Find(fa[x]);
}
bool check(int x)
{
	int p=fa[1];
	for(int i=2;i<=x;i++)
	{
		if(p!=fa[i]) return false;
	}
	return true;
}
ll bfs(int x)
{
	if(!x) return 0;
	
	int tip=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=cnt;i++) e[i].book=0;
	if(check(x)) tip=(tip+1)%mod;
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=cnt;j++)
		{
			if((e[j].u==i || e[j].v==i) && !e[j].book)
			{
				e[j].book=1;
				int f1=Find(i),f2;
				if(e[j].u==i) f2=Find(e[j].v);
				if(e[j].v==i) f2=Find(e[j].u);
				if(f1!=f2)
				{
					fa[f2]=f1;
				}
			}
			if(check(x)) tip=(tip+1)%mod;
		}
	}
	return tip;
}
ll ans;
ll h=0;
void dfs(int x,int y)
{
	if(x-1==n) return;
	ans=(ans+bfs(x)%mod)%mod;
	for(int i=y+1;i<=n;i++)
	{
		g[x+1]=i;
		dfs(x+1,i);
		g[x+1]=0;
	}
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v; scanf("%d%d",&u,&v);
		cnt++; e[cnt].u=u,e[cnt].v=v;
	}
	dfs(0,0);
	printf("%lld",ans%mod);
	
	return 0;
}
