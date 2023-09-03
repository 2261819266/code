#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int N=500009,M=1000009,mod=1000000007;
int ksm(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
struct node{
	int next,to;
}edge[M*2];
int head[N],edge_cnt=0;
void Add_edge(int from,int to)
{
	edge[++edge_cnt].next=head[from];
	edge[edge_cnt].to=to;
	head[from]=edge_cnt;
}
int color[N],color_cnt;
int dfn[N],low[N],stack[N],top,id_cnt=0;
void tarjan(int now,int fa)
{
//	cout<<now<<" "<<fa<<endl;
	dfn[now]=low[now]=++id_cnt;
	stack[++top]=now;
	for(int i=head[now];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=fa)
		{
			if(dfn[v]) low[now]=min(low[now],dfn[v]);
			else tarjan(v,now),low[now]=min(low[now],low[v]);
		}
	}
	if(dfn[now]==low[now])
	{
//	cout<<now<<endl;
//	cout<<dfn[now]<<" "<<low[now]<<endl;
//		cout<<color_cnt<<endl;
		color_cnt++;
//		cout<<color_cnt<<endl;
		while(stack[top]!=now)
		color[stack[top--]]=color_cnt;
		color[stack[top--]]=color_cnt;
	}
}
int n,m;
void readIn()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		Add_edge(x,y);
		Add_edge(y,x);
	}
	tarjan(1,0);
//	for(int i=1;i<=n;i++) cout<<color[i]<<" ";
}
node edge2[N*2];
int head2[N],edge2_cnt=0;
void Add_edge2(int from,int to)
{
	edge2[++edge2_cnt].next=head2[from];
	edge2[edge2_cnt].to=to;
	head2[from]=edge2_cnt;
}
int free_cnt=0,gs[N];
void make_graph()
{
	for(int i=1;i<=n;i++)
	{
		gs[color[i]]++;
		for(int j=head[i];j;j=edge[j].next)
		if(color[i]!=color[edge[j].to]) Add_edge2(color[i],color[edge[j].to]);
		else free_cnt++;
	}
	free_cnt/=2;
}
int dp1[N],dp2[N],siz[N],siz2[N];
void dfs1(int now,int fa)
{
	dp1[now]=ksm(2,gs[now]);
	dp2[now]=dp1[now]-1;
	siz[now]=1;
	siz2[now]=gs[now];
	for(int i=head2[now];i;i=edge2[i].next)
	{
		int v=edge2[i].to;
		if(v!=fa)
		{
			dfs1(v,now);
			if(siz[v]==1) dp1[now]=dp1[now]*(ksm(2,siz[v]-1)+dp1[v])%mod;
			else dp1[now]=dp1[now]*(ksm(2,siz[v]-1)+dp1[v]-1)%mod;
			siz[now]+=siz[v];
			siz2[now]+=siz2[v];
		}
	}
}
signed main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	readIn();
	make_graph();
	dfs1(1,0);
	int ans=0;
	for(int i=1;i<=color_cnt;i++) ans=(ans+dp1[i])%mod;
	for(int i=1;i<=color_cnt;i++) ans=(ans-ksm(2,siz[i]-1))%mod;
	ans=ans*ksm(2,free_cnt)%mod;
//	ans=(ans-ksm(2,m))%mod;
	ans=(ans%mod+mod)%mod;
	printf("%lld\n",ans);
}
