#include<cstdio>
#include<cstring>
#include<algorithm>
//#define reg register
#define mod 1000000007
#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)
//#define meow(Aponia...) fprintf(stderr,Aponia)
int n,m,num=1,head[500002],fir[500002],ans;
struct edge
{
	int next,to;
}mp[2000002],e[2000002];
void add(int u,int v)
{
	mp[++num]=(edge){head[u],v};head[u]=num;
	mp[++num]=(edge){head[v],u};head[v]=num;
}
void adde(int u,int v)
{
	e[++num]=(edge){fir[u],v};fir[u]=num;
	e[++num]=(edge){fir[v],u};fir[v]=num;
}
int sum[500002],top,cnt,scc[500002],dfn[500002],low[500002],dfx=0,sz[500002],p2[1000002];
bool vis[500002];
void tarjan(int u,int fa)
{
	dfn[u]=low[u]=++dfx;
	sum[++top]=u;vis[u]=1;
	for(int i=head[u];i;i=mp[i].next)
	if((i/2)!=fa)
	{
		if(!dfn[mp[i].to])
		{
			tarjan(mp[i].to,i/2);
			low[u]=min(low[u],low[mp[i].to]);
		}
		else if(vis[mp[i].to]) low[u]=min(low[u],dfn[mp[i].to]);
	}
	if(dfn[u]==low[u])
	{
		++cnt;
		sz[cnt]=0;
		do
		{
			scc[sum[top]]=cnt;
			++sz[cnt];
			vis[sum[top]]=0;
			--top;
		}while(sum[top+1]!=u);
	}
}
int f[500002][2];
void dfs1(int u,int fa)
{
	f[u][0]=p2[sum[u]];
	f[u][1]=(long long)p2[sum[u]]*(p2[sz[u]]+mod-1)%mod;
	for(int i=fir[u];i;i=e[i].next)
	if(e[i].to!=fa) dfs1(e[i].to,u);
	for(int i=fir[u];i;i=e[i].next)
	if(e[i].to!=fa)
	{
		f[u][0]=(long long)((long long)p2[sum[e[i].to]+1]+f[e[i].to][1]+f[e[i].to][0])*f[u][0]%mod;
		f[u][1]=(long long)((long long)p2[sum[e[i].to]+1]+f[e[i].to][1]+f[e[i].to][0])*f[u][1]%mod;
		sz[u]+=sz[e[i].to];
		sum[u]+=sum[e[i].to]+1;
	}
	f[u][0]=((long long)f[u][0]-p2[sum[u]]+mod)%mod;//not empty
}
void dfs2(int u,int fa,int dep)
{
	ans=(((long long)p2[dep]+mod-1)*p2[sum[1]-sum[u]-dep]%mod*f[u][1]%mod+ans)%mod;
	for(int i=fir[u];i;i=e[i].next)
	if(e[i].to!=fa)
	{
		dfs2(e[i].to,u,dep+1);
	}
}
int R()
{
	int x=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;
	return x;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
//	scanf("%d%d",&n,&m);
	n=R();m=R();
	p2[0]=1;
	for(int i=1;i<=1000000;++i) p2[i]=p2[i-1]*2%mod;
	for(int i=1,u,v;i<=m;++i) /*scanf("%d%d",&u,&v)*/u=R(),v=R(),add(u,v);
	tarjan(1,0);
	memset(sum,0,sizeof(sum));num=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=head[i];j;j=mp[j].next)
		{
			if(mp[j].to>=i)
			{
				if(scc[mp[j].to]!=scc[i]) adde(scc[mp[j].to],scc[i]);
				else ++sum[scc[i]];
			}
		}
	}
//	meow("cnt:%d\n",cnt);
//	for(int i=1;i<=n;++i) meow("scc[%d]=%d\n",i,scc[i]);
//	for(int i=1;i<=cnt;++i) meow("i:%d sz:%d sum:%d\n",i,sz[i],sum[i]);
	dfs1(1,1);
	ans=(f[1][0]+f[1][1])%mod;
	dfs2(1,1,0);
//	for(int i=1;i<=cnt;++i)
//	{
//		meow("%d 0:%d 1:%d\n",i,f[i][0],f[i][1]);
//	}
	printf("%d\n",ans);
	return 0;
}
