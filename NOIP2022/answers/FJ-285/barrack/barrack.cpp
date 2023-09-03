#include <bits/stdc++.h>
using namespace std;
bool ST;
const int N = 501000;

int n, m;
vector<int> nxt[N], G[N];
int dfn[N], low[N], tot = 1, color[N], tol = 1, val[N], sz[N];
typedef pair<int, int> pii;
set<pii> cut;
void tarjan(int n, int f) {
	dfn[n] = low[n] = tot++;
	for (int i : nxt[n])
		if (i != f)
			if (dfn[i]) low[n] = min(low[n], dfn[i]);
			else tarjan(i, n), low[n] = min(low[n], low[i]);
	for (int i : nxt[n])
		if (low[i] > dfn[n]) cut.insert({i, n}), cut.insert({n, i}); 
}
void dfs(int n) {
	sz[color[n] = tol]++;
	for (int i : nxt[n])
		if (!cut.count({n, i}) && !color[i]) dfs(i);
}
int fa[N][20], dep[N];
void ddfs(int n, int f) {
	for (int i : G[n])
		if (i != f) fa[i][0] = n, dep[i] = dep[n] + 1, ddfs(i, n);
}
inline int lca(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);
	int d = dep[v] - dep[u];
	for (int i = 19; i >= 0; i--)
		if ((d >> i) & 1) v = fa[v][i];
	if (u == v) return u;
	for (int i = 19; i >= 0; i--)
		if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
int all = 0;
void dfz(int n, int f) {
	for (int i : G[n])
		if (i != f) dfz(i, n), val[n] += val[i];
	if (val[n]) all++;
}
typedef long long ll;
const int P = 1e9 + 7;
inline ll qpow(ll a, ll b) {
	ll res = 1;
	for (; b; b >>= 1, a = a * a % P)
		if (b & 1) res = res * a % P;
	return res;
}
ll ans = 0;
bool ED;
int main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
//	printf("mem: %lf\n", (&ST - &ED) / 1024.0 / 1024.0);
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; i++) scanf("%d%d", &u, &v), nxt[u].push_back(v), nxt[v].push_back(u);
	tarjan(1, 1);
	
//	for (pii i : cut) printf("%d %d\n", i.first, i.second);
	
	for (int i = 1; i <= n; i++)
		if (!color[i]) dfs(i), tol++;
	for (pii i : cut) G[color[i.first]].push_back(color[i.second]);
		
//	for (int i = 1; i < tol; i++)
//		for (int j : G[i]) printf("!%d %d\n", i, j);
		
//	for (int i = 1; i <= n; i++) printf("%d : %d\n", i, color[i]);
	
	ddfs(1, 1);
	for (int j = 1; j < 20; j++)
		for (int i = 1; i <= n; i++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
	
	for (int i = 1; i < 1 << (tol - 1); i++) {
//		int l, r;
//		scanf("%d%d", &l, &r);
//		printf("%d\n", lca(l, r));
		
		for (int j = 1; j < tol; j++) val[j] = 0;
		for (int j = 1; j < tol; j++)
			for (int k = j + 1; k < tol; k++)
				if (((i >> j - 1) & 1) && ((i >> k - 1) & 1)) {
					int l = lca(j, k);
//					printf("!!!%d %d %d\n", j, k, l);
					val[j]++, val[k]++, val[l] -= 2;
				}
		all = 0, dfz(1, 1);
		ll t = qpow(2, m - all);
		for (int j = 1; j < tol; j++)
			if ((i >> j - 1) & 1) t = t * ((qpow(2, sz[j]) - 1 + P) % P) % P;
		ans = (ans + t) % P;
//		printf("%d : %d\n", i, all);
	}
	printf("%lld\n", ans);
	return 0;
}
