#include <bits/stdc++.h>
const int mod = 1e9 + 7, N = 5e5 + 10, M = 1e6 + 10;
int n, m;
struct Edge {
	int u, to, nxt;
	bool p;
} edge[M << 1];
long long qpow(int a, int b) {
	long long res = 1, x = a;
	while (b) {
		if (b & 1) res = res * x % mod;
		x = x * x % mod;
		b >>= 1;
	}
	return res;
}
long long inv2;
int cnt = 1;
int head[N];
long long pw[N + M];
void add(int from, int to) {
	edge[++cnt].u = from, edge[cnt].to = to, edge[cnt].nxt = head[from];
	head[from] = cnt;
}
int dfn[N], low[N], ti;
int st[N], top;
bool instack[N];
void dfs(int u, int rk, int f) {
	dfn[u] = low[u] = ++ti;
	st[++top] = u;
	instack[u] = 1;
	for (int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].to;
		if (i == rk or (i ^ 1) == rk) {
			continue;
		}
		if (!dfn[v]) {
			dfs(v, i, u);
			low[u] = std::min(low[u], low[v]);
		}
		else {
		  if (instack[v])
			  low[u] = std::min(low[u], dfn[v]);
			if (low[u] > dfn[v]) {
				edge[i].p = edge[i ^ 1].p = 1;
			}
		}
	}
	if (low[u] > dfn[f]) {
		edge[rk].p = edge[rk ^ 1].p = 1;
	}
	instack[u] = 0;
	top--;
}
int tot;
int siz[N], ecc[N], w[N];
std::vector<int> g[N];
bool vis[N];
void work(int u, int f) {
	siz[tot]++;
	vis[u] = 1, ecc[u] = tot;
	for (int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].to;
		if (vis[v] or edge[i].p) continue;
		work(v, u);
	}
}
long long dp[N][2];
long long ans;
void calc(int u, int f) {
	dp[u][0] = pw[m] * w[u];
	dp[u][1] = w[u];
	for (int v : g[u]) {
		if (v == f) continue;
		calc(v, u);
		dp[u][0] = (dp[u][0] + dp[u][0] * dp[v][1] % mod * inv2 % mod);
		dp[u][1] = (dp[u][1] + dp[u][1] * dp[v][1] % mod * inv2 % mod);
		dp[u][0] %= mod, dp[u][1] %= mod;
	}
	ans += dp[u][0];
	ans %= mod;
}
int main() {
  freopen("barrack.in", "r", stdin);
  freopen("barrack.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> n >> m;
  pw[0] = 1;
  for (int i = 1; i <= n + m; i++) pw[i] = pw[i - 1] * 2 % mod;
  inv2 = qpow(2, mod - 2);
	for (int i = 1; i <= m; i++) {
  	int u, v;
  	std::cin >> u >> v;
  	add(u, v), add(v, u);
	}
	dfs(1, 0, 0);
	for (int i = 1; i <= n; i++) 
	  if (!vis[i]) {
	  	++tot;
	  	work(i, 0);
		}
	if (tot == 1) {
		std::cout << (pw[n] - 1 + mod) * pw[m] % mod << "\n";
		return 0;
	}
	int tmp = 0;
	for (int i = 2; i <= cnt; i += 2) {
		if (edge[i].p) {
			tmp++;
			int u = ecc[edge[i].u], v = ecc[edge[i].to];
			g[u].push_back(v), g[v].push_back(u); 
		}
	}
	for (int i = 1; i <= tot; i++) w[i] = (pw[siz[i]] - 1 + mod) % mod;
	calc(1, 0);
	std::cout << ans << "\n";
  return 0;
}

