#include<bits/stdc++.h>
#define rep(i,a,b) for(int i(a);i<=b;++i)
#define per(i,a,b) for(int i(a);i>=b;--i)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define swap(a,b) a^=b^=a^=b
inline int read()
{
	int x(0),f(1);
	char c=getchar();
	while(c<'0'||c>'9')
	{
		f=(c^'-'?1:-1);
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
using namespace std;
typedef long long ll;
const int N=5e5+5,mod=1e9+7;
int head[N],cnt=0,head2[N],cnt2=0;
int dfn[N],low[N],col[N],val[N],times=0;
bool vis[N];
vector<vector<int> > BCC;
stack<int> st;
struct edge {int v,nxt;} e[N<<1],e2[N<<1];
inline void add(int u,int v) {e[++cnt]={v,head[u]};head[u]=cnt;}
inline void add2(int u,int v) {e2[++cnt2]={v,head2[u]};head2[u]=cnt2;}
void tarjan(int u,int fa)
{
	dfn[u]=low[u]=++times;
	st.push(u);
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa)
			continue;
		if(!dfn[v])
		{
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[u]<low[v])
			{
				vector<int> temp;
				while(st.top()!=v)
				{
					temp.push_back(st.top());
					col[st.top()]=BCC.size()+1;
					st.pop();
				}
				temp.push_back(st.top());
				col[st.top()]=BCC.size()+1;
				st.pop();
				BCC.push_back(temp);
			}
		}
		else
			low[u]=min(low[u],dfn[v]);
	}
}
inline int BFS(int x)
{
	ll ans=val[x],temp=val[x];
	queue<int> q;
	q.push(x);
	while(q.size())
	{
		int u=q.front();
		q.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(vis[v])
				continue;
			q.push(v);
			temp=temp*val[v]%mod;
			ans=(ans+temp)%mod;
		}
	}
	return ans;
}
signed main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int n=read(),m=read();
	fill(val+1,val+1+n,1);
	while(m--)
	{
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	tarjan(1,0);
	if(st.size())
	{
		vector<int> temp;
		while(st.size())
		{
			temp.push_back(st.top());
			col[st.top()]=BCC.size()+1;
			st.pop();
		}
		BCC.push_back(temp);
	}
	rep(u,1,n)
	{
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(!vis[v]&&col[u]==col[v])
				val[col[u]]=(val[col[u]]<<1)%mod;
		}
		vis[u]=1;
	}
	rep(u,1,n)
	{
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(col[u]!=col[v])
			{
				add2(u,v);
				add2(v,u);
			}
		}
	}
	ll ans=0;
	rep(i,0,BCC.size()+1)
	{
		memset(vis,0,sizeof vis);
		ans=(ans+BFS(i))%mod;
	}
	printf("%lld",ans);
	return 0;
}