#include <cstdio>
#include <cstring>
#include <algorithm>

template <class T>
inline void read(T &x) {
	static char s;
	static bool opt;
	while (s = getchar(), (s < '0' || s > '9') && s != '-');
	x = (opt = s == '-') ? 0 : s - '0';
	while (s = getchar(), s >= '0' && s <= '9') x = x * 10 + s - '0';
	if (opt) x = ~x + 1;
}

int qpow(int a, int b, int p) {
	int ans = 1;
	for (; b; b >>= 1) {
		if (b & 1) ans = 1ll * ans * a % p;
		a = 1ll * a * a % p;
	}
	return ans;
}

const int N = 500100, M = 1000100;
const int mod = 1e9 + 7;

void add(int &x, const int &y) {
	x += y;
	if (x >= mod) x -= mod;
}

int n, m;

int pw[1000001];

struct adj {
	int tot = 1, head[N], ver[M * 2], Next[M * 2]; bool ban[M * 2];
	void add_edge(int u, int v) {
		ver[++ tot] = v;    Next[tot] = head[u];    head[u] = tot;
	}
} G, V;

int dfsClock, dfn[N], low[N];

void tarjan(int u, int in_edge) {
	dfn[u] = low[u] = ++ dfsClock;

	for (int i = G.head[u]; i; i = G.Next[i]) {
		int v = G.ver[i];
		if (!dfn[v]) {
			tarjan(v, i);
			low[u] = std::min(low[u], low[v]);

			V.add_edge(u, v), V.ban[V.tot] = dfn[u] < low[v];
		} else if ((i ^ 1) != in_edge) {
			low[u] = std::min(low[u], dfn[v]);
		}
	}
}

int cnt[N];

void dfs(int u) {
	for (int i = V.head[u]; i; i = V.Next[i]) {
		int v = V.ver[i];

		cnt[v] = cnt[u] + V.ban[i];

		dfs(v);
	}
}

namespace sub1 {
	bool check() { return n <= 3000; }

	int DfsClock, Dfn[N], Idx[N], sze[N];

	void dfs1(int u) {
		DfsClock ++;
		Dfn[u] = DfsClock, Idx[DfsClock] = u;

		sze[u] = 1;

		for (int i = V.head[u]; i; i = V.Next[i]) {
			int v = V.ver[i];

			dfs1(v);

			sze[u] += sze[v];
		}
	}

	int le(int u) { return Dfn[u]; }
	int rg(int u) { return Dfn[u] + sze[u] - 1; }

	int f[N];

	void dp(int u) {
		f[u] = 1;

		for (int i = V.head[u]; i; i = V.Next[i]) {
			int v = V.ver[i];

			dp(v);

			int net_f = 1ll * f[u] * pw[sze[v]] % mod;

			int l = le(v), r = rg(v);

			for (int h = l; h <= r; h ++) {
				int x = Idx[h];
				net_f = (net_f + 1ll * f[u] * f[x] % mod * pw[sze[v] - (sze[x] - 1) - (cnt[x] - cnt[u])]) % mod;
			}

			for (int h = l; h <= r; h ++) {
				int x = Idx[h];
				for (int hp = Dfn[u] + 1; hp < l; hp ++) {
					int y = Idx[hp];
					net_f = (net_f + 1ll * f[x] * f[y] % mod * pw[r - Dfn[u] - (sze[x] - 1) - (sze[y] - 1) - (cnt[x] + cnt[y] - 2 * cnt[u])]) % mod;
				}
			}

			f[u] = net_f;
		}
	}

	void ma() {
		dfs1(1);
		dp(1);

		int sum = 0;
		for (int i = 1; i <= n; i ++) add(sum, 1ll * f[i] * pw[n - sze[i]] % mod);

		printf("%d\n", 1ll * sum * pw[m - (n - 1)] % mod);
	}
}

namespace sub2 {
	bool check() { return m == n - 1; }

	void ma() {
		int ans = 0;
		ans = (ans + 1ll * pw[n - 1] * n) % mod;
		ans = (ans + 1ll * pw[n - 2] * (n * (n - 1) / 2)) % mod;

		printf("%d\n", ans);
	}
}

int main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);

	read(n), read(m);

	for (int i = 1, u, v; i <= m; i ++) {
		read(u), read(v);
		G.add_edge(u, v), G.add_edge(v, u);
	}

	tarjan(1, 0);

	dfs(1);

	pw[0] = 1;
	for (int i = 1; i <= 1000000; i ++) pw[i] = 2ll * pw[i - 1] % mod;

	if (sub1::check()) sub1::ma();
	else if (sub2::check()) sub2::ma();

	return 0;
}
