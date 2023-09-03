#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar());
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x;
}
const int maxN=500010;
const int maxM=1000010;
int n,m;
struct edget
{
	int v,nxt;
}e[maxM*2];
int cnt_edge,head[maxN];
void add_edge(int u,int v)
{
	cnt_edge++;
	e[cnt_edge]={v,head[u]};
	head[u]=cnt_edge;
}
vector<int> stk;
int low[maxN],dfn[maxN],cnt_dfn;
int cnt_node,s[maxN],id[maxN];
vector<pair<int,int>> cutedge;
void dfs(int u,int in)
{
	stk.push_back(u);
	low[u]=dfn[u]=++cnt_dfn;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==in) continue;
		if(!dfn[v])
		{
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]==dfn[v]) cutedge.push_back({u,v});
		}
		else low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		cnt_node++;
		while(stk.back()!=u)
		{
			s[cnt_node]++;
			id[stk.back()]=cnt_node;
			stk.pop_back();
		}
		s[cnt_node]++;
		id[u]=cnt_node;
		stk.pop_back();
	}
}
const int mod=1e9+7;
const int inv2=(mod+1)/2;
int pow2[maxM];
vector<int> t[maxN];
int f[maxN];
int ans;
void dfs2(int u,int pa=0)
{
	f[u]=1;
	for(int v:t[u])
	{
		if(v==pa) continue;
		dfs2(v,u);
		f[u]=(f[u]+(long long)f[v]*inv2%mod*f[u])%mod;
	}
	ans=(ans+(long long)f[u]*(pow2[s[u]]-1))%mod;
	f[u]=(long long)f[u]*pow2[s[u]]%mod-1;
	if(f[u]<0) f[u]+=mod;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	pow2[0]=1;
	for(int i=1;i<=max(n,m);i++) pow2[i]=pow2[i-1]*2%mod;
	for(auto i:cutedge)
	{
		t[id[i.first]].push_back(id[i.second]);
		t[id[i.second]].push_back(id[i.first]);
	}
	dfs2(1);
	ans=(long long)ans*pow2[m]%mod;
	printf("%d\n",ans);
	return 0;
}
