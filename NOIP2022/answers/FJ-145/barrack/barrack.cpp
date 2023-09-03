#include<bits/stdc++.h>
#define LL long long
#define mod 1000000007
using namespace std;
int n,m,dfn_t=0,edge_t=0,e_t=0,st_t=0,vec_t=0,cnt=0;
LL ans=0;
int la[500002],lae[500002],dfn[500002],low[500002],st[500002],rt[500002],sum[500002];
LL pw[1000002];
LL f[500002][3];
bool ins[500002];
vector<int> vec[1000002];
struct aaa
{
	int to,nx;
}edge[2000002],e[2000002];
inline void add_edge(int x,int y,int &edge_t,int la[],aaa edge[])
{
	//printf("ADD %d %d\n",x,y);
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void Tarjan(int x,int f)
{
	dfn[x]=low[x]=(++dfn_t),ins[st[++st_t]=x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f)
	{
		if(!dfn[v])Tarjan(v,x),low[x]=min(low[x],low[v]);
		else if(ins[v])low[x]=min(low[x],dfn[v]);
	}
	if(low[x]==dfn[x])
	{
		++vec_t;
		for(;st_t && st[st_t+1]!=x;--st_t)vec[vec_t].push_back(st[st_t]),ins[st[st_t]]=0,rt[st[st_t]]=vec_t;
	}
	//printf("%d: dfn:%d low:%d\n",x,dfn[x],low[x]);
}
inline void dfs(int x,int fa)
{
	int siz=vec[x].size();
	f[x][0]=1;
	f[x][1]=0;
	f[x][2]=pw[siz]-1;
	sum[x]=0;
	for(int i=lae[x],v;i;i=e[i].nx)
		if((v=e[i].to)!=fa)
		{
			dfs(v,x),sum[x]+=sum[v]+1;
			f[x][2]=(f[x][2]*(f[v][0]*2+f[v][1]+f[v][2])+f[x][1]*(f[v][1]+f[v][2]))%mod;
			f[x][1]=(f[x][1]*f[v][0]*2+f[x][0]*(f[v][1]+f[v][2]))%mod;
			f[x][0]=(f[x][0]*f[v][0]*2)%mod;
		}
	//assert(vec_t-1-sum[x]>=0);
	(ans+=f[x][2]*pw[vec_t-1-sum[x]])%=mod;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m),pw[0]=1,cnt=m;
	for(int i=1;i<=m;++i)pw[i]=(pw[i-1]<<1)%mod;
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),add_edge(x,y,edge_t,la,edge);
	Tarjan(1,0);
	
	/*for(int i=1;i<=vec_t;++i)
	{
		printf("%d: ",vec[i].size());
		for(int j=0;j<vec[i].size();++j)printf("%d ",vec[i][j]);
		puts("");
	}
	
	puts("");*/
	
	//printf("vec_t:%d\n",vec_t);
	
	for(int i=1,x,y;i<=edge_t;i+=2)
	{
		x=edge[i].to,y=edge[i+1].to;
		if(rt[x]^rt[y])add_edge(rt[x],rt[y],e_t,lae,e),--cnt;
	}
	
	dfs(1,0),(ans*=pw[cnt])%=mod;
	
	//printf("cnt:%d\n",cnt);
	
	return 0&printf("%lld",(ans+mod)%mod);
}
