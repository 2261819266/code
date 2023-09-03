#include<cstdio>
#include<vector>
#include<cstring>
#define mset(arr,val) memset(arr,val,sizeof(arr))
using namespace std;
typedef long long ll;
const ll SIZE=2e6+10,mod=1e9+7;
inline ll read()
{
	ll x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x*10)+(ch^48),ch=getchar();
	return x;
}
inline ll qpow(ll base,ll power)
{
	ll res=1;
	while(power)
	{
		if(power&1ll)res=(res*base)%mod;
		base=(base*base)%mod,power>>=1;
	}
	return res;
}
vector<ll>nxt[SIZE];
ll n,m,head[SIZE],sizee,scc[SIZE],dpth[SIZE],sizescc,sum[SIZE],dp[SIZE][2],pnt[SIZE],edg[SIZE],sume[SIZE],sizet[SIZE],bin[SIZE],f[SIZE][2],top,ans,xres[SIZE];
bool vst[SIZE],exi[SIZE],brg[SIZE];
struct edge{ll u,v,nxt;}e[SIZE];
inline void add(ll u,ll v){e[sizee]={u,v,head[u]},head[u]=sizee++;}
inline void add_edge(ll u,ll v){add(u,v),add(v,u);}
void dfs1(ll thisp)
{
	vst[thisp]=true;
	for(ll i=head[thisp];~i;i=e[i].nxt)if(!vst[e[i].v])dpth[e[i].v]=dpth[thisp]+1,exi[i]=exi[i^1]=true,dfs1(e[i].v);
}
void dfs2(ll thisp,ll lst)
{
	for(ll i=head[thisp];~i;i=e[i].nxt)if(exi[i]&&e[i].v!=lst)
	{
		dfs2(e[i].v,thisp),sum[thisp]+=sum[e[i].v];
		if(!sum[e[i].v])brg[i]=brg[i^1]=true;
	}
}
void dfs3(ll thisp)
{
	scc[thisp]=sizescc,pnt[sizescc]++,vst[thisp]=true;
	for(ll i=head[thisp];~i;i=e[i].nxt)if(exi[i]&&!brg[i]&&!vst[e[i].v])dfs3(e[i].v);
}
void dfs4(ll thisp,ll lst)
{
	sume[thisp]=edg[thisp];
	for(ll NXT:nxt[thisp])if(NXT!=lst)
	{
		dfs4(NXT,thisp);
		sume[thisp]+=sume[NXT]+1;
	}
	f[top=0][0]=1;
	for(ll NXT:nxt[thisp])if(NXT!=lst)bin[++top]=NXT;
	for(ll i=1;i<=top;i++)
	{
		f[i][0]=(f[i-1][0]*(2*dp[bin[i]][0])%mod)%mod;
	    f[i][1]=((f[i-1][0]*dp[bin[i]][1])%mod+(f[i-1][1]*dp[bin[i]][1])%mod+(f[i-1][1]*2*dp[bin[i]][0])%mod)%mod;
//	    printf("! %d %d\n",f[i][0],f[i][1]);
	}
	dp[thisp][0]=(f[top][0]*qpow(2,edg[thisp]))%mod;
	xres[thisp]=dp[thisp][1]=(f[top][0]*(((qpow(2,pnt[thisp])-1+mod))%mod*qpow(2,edg[thisp]))%mod)%mod;
//	printf("Xres %d\n",xres[thisp]);
	//self only
	xres[thisp]=(xres[thisp]+(((f[top][1]*(qpow(2,pnt[thisp])-1+mod)%mod)%mod*qpow(2,edg[thisp]))%mod))%mod;
	dp[thisp][1]=(dp[thisp][1]+(((f[top][1]*qpow(2,pnt[thisp]))%mod*qpow(2,edg[thisp]))%mod))%mod;
	//self or son
//	printf("XRES %d %d\n",thisp,xres[thisp]);
}
int main() 
{
	freopen("barrack.in","r",stdin),freopen("barrack.out","w",stdout);
//	freopen("barrack4.in","r",stdin);
	mset(head,-1);
	n=read(),m=read();
	for(ll i=1;i<=m;i++)add_edge(read(),read());
	dfs1(1);
	for(ll i=0;i<sizee;i++)if(!exi[i]&&dpth[e[i].u]>dpth[e[i].v])sum[e[i].u]++,sum[e[i].v]--;
	dfs2(1,0);
	mset(vst,0);
	for(ll i=1;i<=n;i++)if(!vst[i])sizescc++,dfs3(i);
	for(ll thisp=1;thisp<=n;thisp++)for(ll i=head[thisp];~i;i=e[i].nxt)if(scc[thisp]!=scc[e[i].v])nxt[scc[thisp]].push_back(scc[e[i].v]);
	for(ll i=0;i<sizee;i+=2)if(scc[e[i].u]==scc[e[i].v])edg[scc[e[i].u]]++;
	dfs4(1,0);
	for(ll i=1;i<=sizescc;i++)ans=(ans+(xres[i]*qpow(2,sume[1]-sume[i]))%mod)%mod;
	printf("%lld",ans);
	return 0;
}
