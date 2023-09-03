#include<cstdio>
#include<vector>
const int N=5e5+7,mod=1e9+7;
typedef long long ll;
const ll Mod=mod,hf=(Mod+1)>>1;
ll qpow(ll x,int y){ll r=1;for(;y;x=x*x%Mod,y>>=1)if(y&1)r=r*x%Mod;return r;}
std::vector<int> to[N];
int dfn[N],low[N],dc;
int stk[N],bel[N],tp,bc;
void tarjan(int i,int l)
{
	dfn[i]=low[i]=++dc;stk[++tp]=i;
	for(int v:to[i])if(v!=l)
		if(!dfn[v])tarjan(v,i),low[i]=std::min(low[i],low[v]);
		else low[i]=std::min(low[i],dfn[v]);
	if(dfn[i]==low[i])
	{
		++bc;do bel[stk[tp]]=bc;
		while(stk[tp--]!=i);
	}
}
std::vector<int> To[N];
int val[N],ans=0;
int f[N],g[N],Tp[N];
void dfs(int i,int l)
{
	ll al=0,lst=0;
	for(int v:To[i])if(v!=l)
	{
		dfs(v,i);
		int p=hf*(f[v]+g[v])%Mod;f[i]=(f[i]+p)%mod;
		al=(al+lst*p)%Mod;lst=(lst+p)%Mod;
	}
	g[i]=(f[i]+al+1LL)*(Tp[val[i]]-1LL)%Mod;
	ans=(ans+g[i])%mod;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d",&u,&v),
		to[u].push_back(v),
		to[v].push_back(u);
	tarjan(1,0);*Tp=1;
	for(int i=1;i<=n;++i)Tp[i]=(Tp[i-1]+Tp[i-1])%mod;
	for(int i=1;i<=n;++i)
	{
		++val[bel[i]];
		for(int v:to[i])if(bel[i]!=bel[v])
			To[bel[i]].push_back(bel[v]);
	}
	dfs(1,0);printf("%lld",qpow(2,m)*ans%Mod);
	return 0;
}
