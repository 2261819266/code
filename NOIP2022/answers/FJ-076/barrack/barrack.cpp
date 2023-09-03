#include<iostream>
#include<cstdio>
#include<vector>

const int N = 5e5 + 5;
const int P = 1e9 + 7;
int qpow(int a,int b)
{
	int res = 1;
	while(b)
	{
		if(b & 1)res = 1ll * res * a % P;
		a = 1ll * a * a % P;
		b >>= 1;
	}
	return res;
}
std::vector<int> e[N],e2[N];
int n,m;

int col[N],col_cnt;
int dfn[N],low[N],cnt;
int stk[N],top;

int siz[N],val[N];

int tar(int u,int fa)
{
	dfn[u] = low[u] = ++cnt;
	stk[++top] = u;
	for(int i = 0;i < e[u].size();++i)
	{
		int v = e[u][i];
		if(v == fa)continue;
		if(!dfn[v])
		{
			tar(v,u);
			low[u] = std::min(low[u],low[v]);
		}
		else
			low[u] = std::min(low[u],dfn[v]);
	}
	if(low[u] == dfn[u])
	{
		col[u] = ++col_cnt;
		++siz[col_cnt];
		while(stk[top] != u)col[stk[top--]] = col_cnt,++siz[col_cnt];
		--top;
	}
}

int up[N];
int vis[N];
//int f[N];
int ans;

void dfs(int u,int fa)
{
	siz[u] = qpow(2,siz[u]);
	val[u] = 1;
	up[u] = 1ll * (siz[u] - 1) * val[u];
	for(int i = 0;i < e2[u].size();++i)
	{
		int v = e2[u][i];
		if(v == fa)continue;
		//printf("u:%d v:%d\n",u,v);
		dfs(v,u);
		up[u] = (2ll * up[u] * val[v] % P + 1ll * (val[u] + up[u])  * up[v] % P) % P;
		val[u] = 2ll * val[u] * val[v] % P;
	}
	//printf("%d %d %lld\n",u,up[u],1ll * up[u] * qpow(2,m-1) % P * qpow(val[u],P-2) % P);
	if(val[u] != qpow(2,col_cnt-1))
		ans = (ans + 1ll * up[u] * qpow(2,col_cnt-2) % P * qpow(val[u],P-2) % P) % P;
	else
		ans = (ans + up[u]) % P;
}

int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= m;++i)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	tar(1,0);
	for(int u = 1;u <= n;++u)
	{
		for(int i = 0;i < e[u].size();++i)
		{
			int v = e[u][i];
			//printf("%d %d %d %d\n",u,v,col[u],col[v]);
			if(col[u] != col[v])
				e2[col[u]].push_back(col[v]);
		}
	}
	dfs(col_cnt,0);
	ans = 1ll * ans * qpow(2,m-col_cnt+1) % P;
	printf("%d\n",ans);
}
