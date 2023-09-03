#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 11;
const int M = 2e6 + 11;
const int mod = 1e9 + 7;
inline int ADD (int a, int b) { if((a += b) >= mod) a -= mod; return a; }
inline int MUL (int a, int b) { return 1ll * a * b % mod; }
struct Edge { int v, nxt; } E[M];
int p[M], eid;
inline void init() { memset(p, -1, sizeof(p)); eid = 0; }
inline void insert (int u, int v) {
	E[eid].v = v;
	E[eid].nxt = p[u];
	p[u] = eid++;
}
int dfn[N], low[N], CLCK, scc[N];
int stk[N], tp = 0;
int U[N], V[N], cnt = 0;
inline void dfs (int u, int fa) {
	dfn[u] = low[u] = ++CLCK;
	stk[++tp] = u;
	for(int i = p[u]; i != -1; i = E[i].nxt) {
		int v = E[i].v;
		if(v == fa) continue;
		if(dfn[v]) {
			low[u] = min(low[u], dfn[v]);
		} else {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		}
	}
	if(low[u] == dfn[u]) {
		cnt++;
		U[cnt] = u, V[cnt] = fa;
		while(stk[tp] != u) scc[stk[tp--]] = cnt;
		scc[stk[tp--]] = cnt;
	}
}
int nd[M], snd[M], toted;
int pw[M], fa[M], sz[M];
inline int get (int x) { if(fa[x] == x) return x; return fa[x] = get(fa[x]); }
int main () {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
//	大样例全是链 + 一些断点捏！ 
	int n, m; scanf("%d%d", &n, &m);
	init();
	pw[0] = 1; for(int i = 1; i <= n + m; i++) pw[i] = ADD(pw[i - 1], pw[i - 1]);
	for(int i = 0, u, v; i < m; i++) {
		scanf("%d%d", &u, &v);
		insert(u, v), insert(v, u);
	}
	dfs(1, 0);
	for(int u = 1; u <= n; u++) {
		nd[scc[u]]++;
		for(int i = p[u]; i != -1; i = E[i].nxt) {
			int v = E[i].v;
			if(scc[u] == scc[v]) {
				toted++;
			}
		}
	}
	for(int i = 0; i < cnt; i++) {
		U[i] = scc[U[i + 1]], V[i] = scc[V[i + 1]];
	}
	toted >>= 1;
	n = cnt, m = cnt - 1;
	int ans = 0, tmp;
	for(int S = 0; S < (1 << m); S++) {
		for(int i = 1; i <= n; i++) fa[i] = i;
		for(int i = 1; i <= n; i++) snd[i] = nd[i];
		for(int i = 0; i < m; i++) {
			if((S >> i) & 1) {
				int x = get(U[i]), y = get(V[i]);
				if(x != y) {
					snd[y] += snd[x];
					fa[x] = y;
				}
			}
		}
		tmp = 0;
		for(int i = 1; i <= n; i++) {
			if(fa[i] == i) {
				tmp = ADD(tmp, MUL(pw[snd[i]] - 1, pw[toted]));
			}
		}
		ans = ADD(ans, tmp);
	}
	printf("%d", ans);
	return 0;
}
//				printf("%d %d %d %d\n", snd[i], toted, pw[snd[i]] - 1, pw[toted]);
