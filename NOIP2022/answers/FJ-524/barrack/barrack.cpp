#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5,mod=1e9+7;

int n,l;

vector <int> g[N],G[N];







int dfn[N],low[N],id[N],vi[N];

bool onstack[N];

vector <vector<int> > bccs;

int tot;stack <int> s;

int val[N],can[N];

void tarjan(int u,int f)
{
	dfn[u]=low[u]=++tot;//cout<<u<<" "<<f<<endl;
	s.push(u);
	onstack[u]=1;
	for (int e=0;e<g[u].size();e++)
	{
		if (g[u][e]==f) continue;
		//if (dfn[g[u][e]] && !onstack[u]) continue;
		if (!dfn[g[u][e]])
		{
			tarjan(g[u][e],u);
			low[u]=min(low[u],low[g[u][e]]);
			if (low[u]<low[g[u][e]])
			{
				vector <int> bcc;
				while (1)
				{
					int q=s.top();s.pop();
					onstack[q]=0;
					bcc.push_back(q);
					id[q]=bccs.size()+1;
					if (q==g[u][e]) break;
				}
				bccs.push_back(bcc);
			}
		}
		else
		{
			low[u]=min(low[u],dfn[g[u][e]]);
		}
	}
}

int bfs(int x)
{
	long long ans=0,te=x;
	queue <int> q;
	q.push(x);
	can[x]=1;
	while (q.size())
	{
		int p=q.front();q.pop();
		if (vi[p]) continue;
		vi[p]=1;
		for (int e=0;e<G[p].size();e++)
		{
			if (vi[g[p][e]] || can[g[p][e]]) continue;
			te=(1ll*te*val[g[x][e]])%mod;
			ans=(ans+te)%mod;
		}
	}
	return ans+val[x];
}

int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d %d",&n,&l);
	for (int i=1;i<=l;i++)
	{
		int u=0,v=0;
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	tarjan(1,0);
	if (s.size())
	{
		vector <int> bcc;
		while (s.size())
		{
			int q=s.top();s.pop();
			bcc.push_back(q);
			id[q]=bccs.size()+1;
		}
		bccs.push_back(bcc);
	}
	int n_=bccs.size()+1;
	for (int i=1;i<=n_;i++) val[i]=1;
	for (int i=1;i<=n;i++)
	{
		for (int e=0;e<g[i].size();e++)
		{
			if (vi[g[i][e]] || id[i]!=id[g[i][e]]) continue;
			val[id[i]]=(1ll*val[id[i]]*2)%mod;
		}
		vi[i]=1;
	}
	for (int i=1;i<=n;i++) val[id[i]]=(val[id[i]]*2)%mod;
	for (int i=1;i<=n;i++)
	{
		for (int e=0;e<g[i].size();e++)
		{
			if (id[i]==id[g[i][e]]) continue;
			G[i].push_back(g[i][e]);
			G[g[i][e]].push_back(i);
		}
	}































	long long ans=0;
	//写挂了qwq
	int y;
	for (int i=1;i<=n_;i++)
	{
		memset(vi,0,sizeof vi);
		ans=(ans+bfs(i))%mod;
	}
	cout<<ans-1<<endl;
	return 0;
}