#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=500003,M=2000003,P=1e9+7; 
bool Mbe;
inline int read()
{
	int x=0,y=1;char ch=getchar();
	while(ch<48||ch>57){if(ch=='-') y=-1;ch=getchar();}
	while(ch>=48&&ch<=57) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*y;
}
/*
n dian m bian liantong

1 有
0 没有
 
只袭击 1 条 路只有袭击各点 会出示
所点是一刻书 
然后 dp

dp[u][1]： 有兵营
dp[v][0]:  meiyou

 
*/
int n,m,idx,dfn[N],low[N],stk[N],sz[N],dcc[N],ctt[N],top,dcc_cnt;
int num=1,fir[N],to[M],nxt[M],dp[N][2];
bool is[M];
struct Edge{
	int u,v;
}eg[M];
inline int qpow(int bs,int k)
{
	int res=1;
	while(k)
	{
		if(k&1) res=res*bs%P;
		bs=bs*bs%P;
		k>>=1;
	}
	return res;
}
inline void add(int u,int v)
{
	to[++num]=v,nxt[num]=fir[u],fir[u]=num;
}
void tarjan(int u,int inn)
{
	dfn[u]=low[u]=++idx,stk[++top]=u;
	for(int i=fir[u],v;i;i=nxt[i])
	{
		if(!dfn[v=to[i]])
		{
			tarjan(v,i),low[u]=min(low[u],low[v]);
			if(dfn[u]<=low[v]) is[i/2]=1;
		}
		else if(i^inn^1) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		int x;
		dcc_cnt++;
		while(x=stk[top--])
		{
			dcc[x]=dcc_cnt,sz[dcc_cnt]++;
			if(x==u) return;
		}
	}
}
void dfs(int u,int fa)
{
//	printf("edfgh %d\n",u);/
	dp[u][1]=((qpow(2,sz[u])-1)%P+P)%P*qpow(2,ctt[u])%P,dp[u][0]=qpow(2,ctt[u])%P;
//	printf("    %lld %lld %lld\n",u,dp[u][1],dp[u][0]);
	for(int i=fir[u],v;i;i=nxt[i]) if((v=to[i])^fa)
	{
		dfs(v,u);
		dp[u][1]=(dp[v][0]*dp[u][1]*2%P+dp[v][1]*dp[u][1]%P+dp[v][1]*dp[u][0]*2%P)%P;
		dp[u][0]=dp[u][0]*dp[v][0]*2%P;
		dp[u][0]%=P;
		dp[u][1]%=P;
//		dp[u][1]=dp[u][1]*(dp[v][0]*2*qpow(2,sz[u]-1)%P*qpow(2,(ctt[u]))%P+dp[v][1]*(qpow(2,sz[u])*qpow(2,ctt[u]))%P)%P;
//		dp[u][0]=dp[u][0]*dp[v][0]*2*qpow(2,ctt[u])%P;
	}
//	
//	printf("%lld %lld %lld\n",u,dp[u][1],dp[u][0]);
}
bool Med;
signed main()
{
//	printf("%.4lf MB\n",(&Med-&Mbe)/1048576.0);
	#define Marsrayd
	#ifdef Marsrayd
		freopen("barrack.in","r",stdin);
		freopen("barrack.out","w",stdout);
	#endif
	n=read(),m=read();
	for(int i=1,u,v;i<=m;i++)
	{
		u=read(),v=read();
		eg[i]={u,v};
		add(u,v),add(v,u);
	}
	tarjan(1,0);
//	puts("dkfshajklsdbnf");
//	for(int i=1;i<=n;i++) printf("%d ",dcc[i]);puts("");
//	for(int i=1;i<=n;i++) printf("%d ",sz[i]);puts("");
	num=0,memset(fir,0,sizeof(fir));
	for(int i=1,u,v;i<=m;i++)
	{
		u=dcc[eg[i].u],v=dcc[eg[i].v];
		if(u==v) ctt[u]++;
		else add(u,v),add(v,u);
	}
//	printf("%lld %lld\n",dcc_cnt,num);
//	for(int i=1;i<=n;i++) printf("%d ",ctt[i]);puts("");
//	puts("fdsahfkjsdf");
////	puts("dfkhajkosdhfuhaiosdf");
//	for(int i=1;i<=n;i++) printf("%lld %lld %lld\n",dcc[i],sz[dcc[i]],ctt[dcc[i]]);puts("");
	int x=1;
	dfs(x,x);
	printf("%lld\n",(long long)dp[x][1]%P);
	return 0;
}


/*
dp[u][1]=dp[v][0]*2*((2^sz[u]-1)*2^(ctt[u]))+dp[v][1]*(2^sz[u]*2^ctt[u])
dp[u][0]=dp[v][0]*2*2^ctt[u]

dp[4][0]=1
dp[4][1]=1

dp[1][0]=


*/
