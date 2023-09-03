#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std ;
const int MAXN = 5e5 + 10 , MAXM = 1e6 + 10 , mod = 1e9 + 7 ;
typedef long long ll ;
int n , m , fir[MAXN] , tot = 1 , w[MAXN] , w2[MAXN] ;
struct edge {int to , nxt ;} e[MAXM << 1] ;
void add (int u , int v) {e[++tot].to = v ; e[tot].nxt = fir[u] ; fir[u] = tot ;}
int dfn[MAXN] , low[MAXN] , c[MAXN] , vis[MAXN] , st[MAXN] , tp , cc , cnt ;
ll pw[MAXM * 2] , f[MAXN] , ans , g[MAXN] ; 
void tarjan (int x , int fa) {
	dfn[x] = low[x] = ++cnt ; vis[x] = 1 ; st[++tp] = x ;
	for (int i = fir[x] ; i ; i = e[i].nxt) {
		if (i == fa) continue ;
		int v = e[i].to ;
		if (!dfn[v]) tarjan (v , i ^ 1) , low[x] = min (low[x] , low[v]) ;
		else if (vis[v]) low[x] = min (low[x] , dfn[v]) ;
	}
	if (dfn[x] == low[x]) {
		c[x] = ++cc ; vis[x] = 0 ;
		for (; st[tp] != x ; tp--) c[st[tp]] = cc , vis[st[tp]] = 0 ;
		tp-- ;
	}
}
vector <int> G[MAXN] ;
int ff[MAXN] , dep[MAXN] , sz[MAXN] , sz2[MAXN] ;
void dfs2 (int x , int fa) {
	int len = (int)G[x].size () ; ff[x] = fa ; dep[x] = dep[fa] + 1 ; sz[x] = 1 ; sz2[x] = w[x] ;
	f[x] = pw[w2[x]] * pw[w[x]] % mod ; sz2[x] = w[x] ;
	for (int i = 0 ; i < len ; i++) {
		int v = G[x][i] ;
		if (v == fa) continue ;
		//printf ("%d->%d\n" , x , v) ;
		dfs2 (v , x) , sz[x] += sz[v] ; sz2[x] += sz2[v] + 1 ;
		f[x] = f[x] * (f[v] + pw[sz2[v] + 1]) % mod ;
		//printf ("%lld\n" , f[v] + pw[sz2[v] + 1]) ; 
	}
	f[x] = (f[x] - pw[sz2[x]]  + mod) % mod ;
	g[x] = f[x] ;
	for (int i = 0 ; i < len ; i++) {
		int v = G[x][i] ;
		if (v == fa) continue ;
		g[x] = (g[x] - f[v] * pw[sz2[x] - sz2[v] - 1] % mod + mod) % mod ;
	}
}
void U (ll &x , ll y) {x = x + y >= mod ? x + y - mod : x + y ;}
int main () {
	freopen ("barrack.in" , "r" , stdin) ;
	freopen ("barrack.out" , "w" , stdout) ;
	scanf ("%d%d" , &n , &m) ; pw[0] = 1 ;
	if (n == 1) return !printf ("1") ;
	for (int i = 1 ; i <= 2e6 ; i++) pw[i] = pw[i - 1] * 2 % mod ;
	bool fl = 1 ;
	for (int i = 1 , u , v ; i <= m ; i++) {
		scanf ("%d%d" , &u , &v) , add (u , v) , add (v , u) ; 
		if (v != u + 1) fl = 0 ;
	}
	//if (fl) return !printf ("%lld\n" , (pw[n - 2] * (((ll)n * (n - 1) / 2) % mod) % mod + pw[n - 1] * n % mod) % mod) ;
	tarjan (1 , 0) ;
	for (int i = 1 ; i <= n ; i++)
		for (int j = fir[i] ; j ; j = e[j].nxt) {
			int v = e[j].to ;
			if (c[i] == c[v]) w[c[i]]++ ;
			else G[c[i]].push_back (c[v]) ; 
		}
	for (int i = 1 ; i <= n ; i++) w2[c[i]]++ ;
	for (int i = 1 ; i <= cc ; i++) w[i] >>= 1 ;
	dfs2 (1 , 0) ;
	for (int i = 1 ; i <= cc ; i++) U (ans , g[i] * pw[m - sz2[i]] % mod) ;
	printf ("%lld\n" , ans) ; 
	return 0 ;
}
