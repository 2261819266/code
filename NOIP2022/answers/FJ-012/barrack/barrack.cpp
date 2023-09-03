#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005,M=2000005;
const ll mod=1e9+7;
inline int rd()
{
	int x=0;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar())
		x=x*10+(ch^48);
	return x;
}
inline void inc(ll &x,ll y)
{  if((x+=y)>=mod) x-=mod;  }
int n,m;
int to[M],nxt[M],cnt=1;
int hd[N];
bool iscut[M];
void add(int u,int v)
{
	nxt[++cnt]=hd[u];
	hd[u]=cnt;
	to[cnt]=v;
}
int dfn[N],cid,low[N];
void tarjan(int u,int f)
{
	low[u]=dfn[u]=++cid;
	for(int i=hd[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==f) continue;
		if(!dfn[v])
		{
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
		}
		else 
			low[u]=min(low[u],dfn[v]);
		if(low[v]>dfn[u])
		{
			iscut[i]=iscut[i^1]=1;
		}
			
	}
}

vector<int> G[N];
int siz[N],sed[N];
int col[N],vcc;
void dfs(int u,int c)
{
	col[u]=c;
	siz[c]++;
	for(int i=hd[u];i;i=nxt[i])
	{
		int v=to[i];
		if(iscut[i])
			continue;
		if(col[v]) continue;
		dfs(v,c);
	}
}
ll pw[N];
ll dp[N][3];
ll ans=0;
int sumed[N];
void redfs(int u,int f)
{
	dp[u][0]=1;
	dp[u][1]=0;
	sumed[u]=sed[u];
	for(int v:G[u])
	{
		if(v==f) continue;
		redfs(v,u);
		sumed[u]+=sumed[v]+1;
		dp[u][2]=(dp[u][0]*(dp[v][1]+dp[v][2]*2)%mod+dp[u][2]*dp[v][0]*2%mod)%mod;
		dp[u][1]=(dp[u][0]*dp[v][1]%mod+dp[u][1]*(dp[v][1]+dp[v][0]*2)%mod)%mod;
		dp[u][0]=dp[u][0]*dp[v][0]*2%mod;
	}
	dp[u][1]=dp[u][1]*pw[siz[u]]%mod;
	inc(dp[u][1],dp[u][0]*(pw[siz[u]]+mod-1)%mod);
	dp[u][0]=dp[u][0]*pw[sed[u]]%mod;
	dp[u][1]=dp[u][1]*pw[sed[u]]%mod;
	dp[u][2]=dp[u][2]*pw[sed[u]]%mod;
//	if(u!=1)
//		inc(ans,dp[u][1]*pw[m-sumed[u]-1]%mod);
//	cout<<u<<' '<<dp[u][0]<<' '<<dp[u][1]<<' '<<dp[u][2]<<endl;
}

int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=rd(),m=rd();
	pw[0]=1;
	for(int i=1;i<=n;i++)
		inc(pw[i],pw[i-1]+pw[i-1]);
	for(int i=1;i<=m;i++)
	{
		int u=rd(),v=rd();
		add(u,v);
		add(v,u);
	}
	tarjan(1,0);
	for(int i=1;i<=n;i++)
		if(!col[i])
			dfs(i,++vcc);
	for(int u=1;u<=n;u++)
		for(int i=hd[u];i;i=nxt[i])
		{
			if(iscut[i])
			{
				int cu=col[u];
				int cv=col[to[i]];
				G[cu].push_back(cv);
			}
			else
				sed[col[u]]++;
		}
	for(int i=1;i<=vcc;i++)	
		sed[i]>>=1;
	
	redfs(1,0);
	inc(ans,dp[1][1]+dp[1][2]);
	
	printf("%lld\n",ans);
	return 0;
}

