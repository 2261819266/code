#include<bits/stdc++.h>
#define PII pair<int, int>
const int N=5e5+99;
const int mod=1e9+7;
const int inf=1e9+99;
using namespace std;
struct edge{
	int to,nex;
}e[N<<2];
int n,m,cnt,head[N],dis[N],son[N],ans;
bool vis[N];
priority_queue<PII,vector<PII>,greater<PII>> q;
inline void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
inline void dij()
{
	memset(dis,inf,sizeof(dis));
	memset(vis,false,sizeof(vis));
	q.push({0,1});
	while(!q.empty())
	{
		auto f=q.top();q.pop();
		int u=f.second;
		if(vis[u])continue;
		vis[u]=true;
		dis[u]=f.first;
		for(int i=head[u];i;i=e[i].nex)
		{
			int v=e[i].to;
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				q.push({dis[v],v});
			}
		}
	}
	return;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	dij();
	memset(vis,false,sizeof(vis));
	int sum=1;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+i*sum)%mod;
		sum=(sum<<1)%mod;
	}
	printf("%d\n",sum);
	return 0;
}
