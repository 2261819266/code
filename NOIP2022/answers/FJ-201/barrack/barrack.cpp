#include <bits/stdc++.h>
#define TIME clock() / CLOCKS_PER_SEC
#define pb emplace_back
using namespace std;
const int N = 5e5 + 5, M = 1e6 + 5, mod = 1e9 + 7;
int n, m, U[M], V[M];
int tot = 1, hd[N], nxt[2 * M], to[2 * M];
void add(int u, int v) {
	to[++tot] = v, nxt[tot] = hd[u], hd[u] = tot;
	to[++tot] = u, nxt[tot] = hd[v], hd[v] = tot;
}
int tim, dfn[N], low[N], col[N], cnt;
bool bri[2 * M];
void tarjan(int u, int ff) {
	dfn[u] = low[u] = ++tim;
	for (int i = hd[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v == ff)
			continue; 
		if (dfn[v] == 0) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > dfn[u]) {
				bri[i] = bri[i ^ 1] = true;
			} 
		} else {
			low[u] = min(low[u], dfn[v]);
		}
	}	
}
bool vis[N];
int szE[N], szN[N], sE[N], sN[N], f[N], g[N], p[N + M];
vector <int> e[N]; 
void dfs(int u) {
	if (vis[u] == true)
		return;
	vis[u] = true;
	col[u] = cnt;
	sN[cnt]++;
	for (int i = hd[u]; i; i = nxt[i]) {
		if (bri[i] == true)
			continue;
		int v = to[i];
		dfs(v);
	}
}
void calc(int u, int ff) {
	szE[u] = sE[u];
	szN[u] = sN[u];
	for (int v : e[u]) {
		if (v == ff)
			continue;
		calc(v, u);
		szE[u] += szE[v] + 1;
		szN[u] += szN[v];
	}
	int val = 1ll * p[sE[u]] * (p[sN[u]] - 1) % mod; 
	f[u] = val;
	g[u] = p[sE[u]];
	for (int v : e[u]) {
		if (v == ff)
			continue;
		f[u] = 1ll * f[u] * (g[v] + p[szE[v] + 1]) % mod;
		g[u] = 1ll * g[u] * (g[v] + p[szE[v] + 1]) % mod;
	}
	g[u] = (g[u] + mod - p[szE[u]]) % mod;
	g[u] = (g[u] + f[u]) % mod;
	f[u] = 1ll * f[u] * p[m - szE[u]] % mod;
}
int main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		U[i] = x;
		V[i] = y;
		add(x, y);
	}
	tarjan(1, 0);
	for (int i = 1; i <= n; i++) {
		if (col[i] == 0) {
			cnt++, dfs(i); 
		}
	}
//	cout << cnt << "\n";
//	for (int i = 1; i <= n; i++)
//		cout << col[i] << " ";
//	cout << "\n";
	for (int i = 1; i <= m; i++) {
		int x = U[i], y = V[i];
		if (col[x] == col[y]) {
			sE[col[x]]++;
		} else {
			e[col[x]].pb(col[y]);
			e[col[y]].pb(col[x]); 
		}
	}
	p[0] = 1;
	for (int i = 1; i <= n + m; i++)
		p[i] = 1ll * p[i - 1] * 2 % mod;
	calc(1, 0);
	int ans = 0;
	for (int i = 1; i <= cnt; i++)
		ans = (ans + f[i]) % mod;
	cout << ans << "\n" ;
//	for (int i = 1; i <= cnt; i++) {
//		cout << sN[i] << " " << sE[i] << " " << szN[i] << " " << szE[i] << "\n";
//	}
//	for (int i = 1; i <= cnt; i++) 
//		cout << f[i] << "\n";
//	cerr << TIME << "ms\n";
	return 0;
}
/*
4 4
1 2
2 3
3 1
1 4
*/
