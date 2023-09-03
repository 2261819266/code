#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define U(i,b,e) for(int i(b),END##i(e);i<=END##i;++i)
#define D(i,e,b) for(int i(e),END##i(b);i>=END##i;--i)

const ll P = 1000000007;
const int N = 500005, MAXM = 4000006;
ll pw2[MAXM];
int n, m, gr[N], to[MAXM], pre[MAXM], ep = 1;
void add(int u, int v, int *tail) {
	to[++ep] = v; pre[ep] = tail[u]; tail[u] = ep; }
#define Iter(z,x,y,t) for(int x,y=t[z];(x=to[y]),y;y=pre[y])

int dfn[N], low[N], brg[MAXM];
void tarjan(int u, int f) {	
	static int dp;
	dfn[u] = low[u] = ++dp;
	Iter (u, v, p, gr) if ((p ^ f) > 1)
		if (!dfn[v]) {
			tarjan(v, p);
			low[u] = min(low[u], low[v]);
			
			if (low[v] > dfn[u])
				brg[p >> 1] = 1;
		} else low[u] = min(low[u], dfn[v]);
}
int col[N], dcp, dSz[N], eSz[N];
void dfs(int u, int c) {
	col[u] = c; ++dSz[c];
	Iter (u, v, p, gr) if (!col[v] && !brg[p >> 1])
		dfs(v, c);
}
int tr[N];

ll f[N][3];
#define M(x) ((x) % P)
void dp(int u, int fa) {
	ll g[2][4] {};
	g[0][0] = pw2[eSz[u]];
	g[1][0] = (pw2[dSz[u]] - 1) * pw2[eSz[u]] % P;
	
	Iter (u, v, p, tr) if (v != fa) {
		dp(v, u);
		ll h[2][4] {};
		h[0][0] = M(g[0][0] * M(2ll * f[v][0]));
		h[0][1] = M(M(g[0][0] * f[v][1]) + M(g[0][1] * M(2ll * f[v][0])));
		h[0][2] = M(M(g[0][1] * f[v][1]) + M(g[0][2] * (2ll * f[v][0] + f[v][1])));
		h[0][3] = M(M(M(g[0][0] * 2ll) * f[v][2]) + M(M(g[0][3] * 2ll) * f[v][0]));
		
		h[1][0] = M(g[1][0] * 2ll * f[v][0]);
		h[1][1] = M(g[1][0] * f[v][1] + M(g[1][1] * M(2ll * f[v][0] + f[v][1])));
		U (x, 0, 1) U (y, 0, 3)
			g[x][y] = h[x][y];
	}
	f[u][0] = g[0][0];
	f[u][1] = M(g[1][0] + g[1][1] + g[0][2] + g[0][1]);
	// kaibai start from a chosen/MERGEN vertex
	f[u][2] = M(g[1][0] + g[1][1] + g[0][2] + g[0][3]);
}

int main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	
	pw2[0] = 1;
	U (i, 1, MAXM - 1) pw2[i] = pw2[i - 1] * 2 % P;
	
	scanf("%d%d", &n, &m);
	int U[MAXM], V[MAXM];
	U (i, 1, m) {
		int u, v; scanf("%d%d", &u, &v);
		add(u, v, gr); add(v, u, gr);
		U[i] = u, V[i] = v;
	}
	
	U (i, 1, n) if (!dfn[i])
		tarjan(i, 0);
	U (i, 1, n) if (!col[i])
		dfs(i, ++dcp);
	U (i, 1, m)
		if (brg[i]) {
			add(col[U[i]], col[V[i]], tr);
			add(col[V[i]], col[U[i]], tr);
		} else {
			++eSz[col[U[i]]];
		}
	dp(1, 0);
	
	printf("%lld", (f[1][2] + P) % P); // at least one barrack
	return 0;
}