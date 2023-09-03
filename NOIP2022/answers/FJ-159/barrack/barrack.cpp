#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,P=1e9+7;
int hd[N],t[2010000],nxt[2010000],tt=1;
int c[N],cnt,sta[N],top;
int dfn[N],low[N],TT,w[N];
vector<int>to[N]; 
long long F[N][N];
long long qpow(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%P;
		a=a*a%P,b>>=1;
	}
	return ans;
}
void tarjan(int u,int f)
{
	dfn[u]=low[u]=++TT,sta[++top]=u;
	for(int i=hd[u];i;i=nxt[i])
	{
		int v=t[i];
		if(!dfn[v])
		{
			tarjan(v,i^1);
			low[u]=min(low[u],low[v]);
		}
		else if(i!=f)low[u]=min(low[u],dfn[v]);
	}
	if(low[u]>=dfn[u])
	{
		int k;++cnt;
		do
		{
//			cerr<<top<<endl;
			k=sta[top--];
			c[k]=cnt;
			++w[cnt];
		}while(k!=u);
	}
}
void add(int u,int v)
{
	t[++tt]=v,nxt[tt]=hd[u],hd[u]=tt;
}
long long ans=0;
int dep[N],sz[N];
int n,m;
void dfs(int u,int f)
{
//	cerr<<"DFS "<<u<<" "<<f<<endl;
	dep[u]=dep[f]+1;sz[u]=1;
	for(int i=dep[u];i<=n;++i)F[u][i]=1;
	for(int v:to[u])
	{
		if(v==f)continue;
		dfs(v,u);
		sz[u]+=sz[v];
		for(int i=dep[v];i<=n;++i)
			F[u][i]=F[u][i]*(F[v][i]%P)%P;
	}
	assert(dep[u]+sz[u]<=n);
	for(int i=dep[u]+sz[u];i<=n;++i)F[u][i]=0;
	for(int i=dep[u];i<dep[u]+sz[u];++i)F[u][i]=F[u][i]*(qpow(2,w[u])-1)%P,ans=(ans+qpow(2,m-i+dep[u])*F[u][i]%P)%P;//,cerr<<F[u][i]<<" "<<i<<" "<<ans<<endl;
//	for(int i=0;i<=n;++i)cerr<<"F["<<u<<"]["<<i<<"]="<<F[u][i]<<endl;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;++i)if(!dfn[i])tarjan(i,0);
	for(int i=1;i<=n;++i)
		for(int j=hd[i];j;j=nxt[j])
		{
			int v=t[j];
			if(c[v]!=c[i])to[c[i]].push_back(c[v]);
		}
	for(int i=1;i<=cnt;++i)
	{
		sort(to[i].begin(),to[i].end());
		to[i].erase(unique(to[i].begin(),to[i].end()),to[i].end());
	}
//	for(int i=1;i<=cnt;++i)
//		for(int j:to[i])cerr<<i<<"->"<<j<<endl;
	dep[0]=-1;
	dfs(1,0);
	
	cout<<ans<<endl;
	return 0;
}
