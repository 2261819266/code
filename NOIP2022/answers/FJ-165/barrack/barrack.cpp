#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 500010;
const int MAXM = 1000010;
const int MOD = 100000007;

inline int add(int a, int b) { return (a+=b)>=MOD?a-MOD:a;}
inline void inc(int& a, int b) { a = add(a, b);}
inline int sub(int a, int b) {return (a-=b)<0?a+MOD:a;}
inline void dec(int& a, int b) { a = sub(a, b);}
inline int mul(int a, int b) {return 1ll*a*b%MOD;}

int n, m, um[MAXM], vm[MAXM];
struct edge{
	int ne, to;
	edge(int N=0,int T=0):ne(N),to(T){}
}e[MAXM<<1];
int fir[MAXN], num = 1;
inline void join(int a, int b) { e[++num] = edge(fir[a], b); fir[a] = num; }
bool vis[MAXN], is[MAXN];
int siz[MAXN], ans = 0, son[MAXN], top[MAXN], anc[MAXN], dep[MAXN], pw2[MAXM];
void dfs1(int u)
{
	vis[u] = 1; siz[u] = 1;
	for(int i=fir[u],v;i;i=e[i].ne) if(!vis[v = e[i].to])
	{
		is[i>>1] = 1;
		anc[v] = u; dep[v] = dep[u]+1;
		dfs1(v);
		siz[u] += siz[v];
		if(siz[son[u]] < siz[v]) son[u] = v;
		inc(ans, sub(add(pw2[siz[v]+1], pw2[n-siz[v]+1]), 4));
		inc(ans, sub(pw2[n], add(pw2[siz[v]], pw2[n-siz[v]]))+1);
	}
}
void dfs2(int u, int t)
{
	top[u] = t;
	if(son[u]) dfs2(son[u], t);
	for(int i=fir[u],v;i;i=e[i].ne) if(anc[v = e[i].to] == u && v != son[u]) dfs2(v, v);
}
inline int LCA(int x, int y)
{
	for(;top[x]^top[y];x=anc[top[x]]) if(dep[top[x]] < dep[top[y]]) swap(x, y);
	return dep[x] < dep[y] ? x : y;
}
int val[MAXN];
void calc(int u)
{
	for(int i=fir[u],v;i;i=e[i].ne) if(anc[v = e[i].to] == u)
	{
		calc(v);
		val[u] += val[v];
		inc(ans, mul(pw2[val[v]]-1, pw2[n]));
	}
}

inline void work()
{
	scanf("%d%d",&n,&m);
	for(int i=pw2[0]=1;i<=m+5;i++) pw2[i] = add(pw2[i-1], pw2[i-1]);
	for(int i=1;i<=m;i++) scanf("%d%d",um+i,vm+i), join(um[i], vm[i]), join(vm[i], um[i]);
	dfs1(1);
	dfs2(1, 1);
	for(int i=1;i<=m;i++) if(!is[i]) ++val[um[i]], ++val[vm[i]], val[LCA(um[i], vm[i])] -= 2;
	calc(1);
	printf("%d\n",ans);
}

int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int T = 1;
//	scanf("%d%*d",&T);
	while(T--) work();
	return 0;
}
/*
1 0
4 3 1 1
001
010
000
000
*/
