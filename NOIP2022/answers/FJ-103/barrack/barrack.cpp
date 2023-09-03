// don't know how to tarjan, i'm fed up
// don't know how to dp, i'm fked up
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5, P = 1000000007;
int n,m;
vector<int> g[N],h[N],tmp;
int dfn[N],low[N],ct;
int dsc[N],nd;
int cnts[N],cnte[N];
void dfs(int u, int prv)
{
	low[u]=dfn[u]=++ct;
	for(int v:g[u])
	{
		if(!dfn[v]) dfs(v,u),low[u]=min(low[u],low[v]);
		else if(v!=prv) { low[u]=min(low[u],low[v]); low[v]=min(low[u],low[v]); }
	}
}
int ksm(int a, int b)
{
	int res=1;
	for(; b; b>>=1,a=(ll)a*a%P) if(b&1) res=(ll)a*res%P;
	return res;
}
int f[N],cte[N];
void dp(int u, int prv)
{
	cte[u]=cnte[u];
	f[u]=ksm(2,cnte[u]+cnts[u]);
	for(int v:h[u])
	{
		if(v==prv) continue;
		dp(v,u); cte[u]+=cte[v]+1;
		f[u]=(ll)f[u]*(f[v]+ksm(2,cte[v]+1))%P;
	}
	f[u]=(f[u]-ksm(2,cte[u])+P)%P;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v; i<=m; i++) scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u);
	dfs(1,0);
	for(int i=1; i<=n; i++) dsc[i]=low[i];
	sort(dsc+1,dsc+n+1); nd=unique(dsc+1,dsc+n+1)-dsc-1;
	for(int i=1; i<=n; i++) low[i]=lower_bound(dsc+1,dsc+nd+1,low[i])-dsc;
//	for(int i=1; i<=n; i++) printf("%d ",low[i]); puts("");
	for(int i=1; i<=n; i++) cnts[low[i]]++;
	for(int i=1; i<=n; i++) 
		for(int j:g[i]) 
			if(low[i]!=low[j]) h[low[i]].push_back(low[j]),h[low[j]].push_back(low[i]);
			else cnte[low[i]]++;
	for(int i=1; i<=nd; i++) cnte[i]>>=1;
//	for(int i=1; i<=nd; i++) printf("cnts=%d cnte=%d\n",cnts[i],cnte[i]);
	for(int i=1; i<=nd; i++)
	{
		sort(h[i].begin(),h[i].end());
		//unique(h[i].begin(),h[i].end());
		tmp.clear();
		for(int j=0; j<(int)h[i].size(); j++) if(j==0 or h[i][j]!=h[i][j-1]) tmp.push_back(h[i][j]);
		h[i]=tmp;
	}
//	for(int i=1; i<=nd; i++) { for(int j:h[i]) printf("%d->%d ",i,j); puts(""); }
	dp(1,0);
	int ans=f[1];
//	for(int i=1; i<=nd; i++) printf("%d\n",f[i]);
	for(int i=2; i<=nd; i++) ans=(ans+(ll)f[i]*ksm(2,m-1-cte[i])%P)%P;
	printf("%d\n",ans);
	return 0;
}

