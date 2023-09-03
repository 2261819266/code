#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 10, M = 2e6 + 10, mod = 1e9 + 7;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], stk[N], id[N], sz[N], t, tt, cnt;
int edges[N];
int H[N], E[M], NE[M];
int twos[M];
int tot;
bool is_leaf[N];
int f[N][2];
int vis[N];

inline int read()
{
	int x = 0, y = 1; char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') y = -1; c = getchar();
	}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * y;
}

inline void add(int h[], int e[], int ne[], int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

inline void tarjan(int u, int p)
{
	dfn[u] = low[u] = ++t, stk[++tt] = u;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int v = e[i];
		if (!dfn[v])
		{
			tarjan(v, i);
			low[u] = min(low[u], low[v]);
		}
		else if (i != (p ^ 1))
			low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u])
	{
		int v;
		cnt++;
		do {
			v = stk[tt--];
			id[v] = cnt;
			sz[cnt]++;
		} while (u != v);
	}
}

inline int mul(int x, int y)
{
	return 1ll * x * y % mod;
}

inline void dfs1(int u, int p)
{
	vis[u] = true, is_leaf[p] = 1;
	for (int i = H[u]; ~i; i = NE[i])
	{
		int v = E[i];
		if (vis[v] || v == p) continue;
		dfs1(v, u);
	}
}

inline void dfs2(int u, int p)
{
	vis[u] = true;
	if (!is_leaf[u])
	{
		f[u][0] = twos[edges[u]];
		f[u][1] = mul(twos[edges[u]], twos[sz[u]] - 1);
		return;
	}
	for (int i = H[u]; ~i; i = NE[i])
	{
		int v = E[i];
		if (v == p || vis[v]) continue;
		dfs2(v, u);
		f[u][0] = (f[u][0] + mul(mul(f[v][0], twos[edges[u]]), 2)) % mod;
		f[u][1] = (f[u][1] + mul(f[v][1], mul(twos[edges[u]], twos[sz[u]] - 1))) % mod;
		f[u][1] = (f[u][1] + mul(f[v][0], mul(mul(twos[edges[u]], twos[sz[u]] - 1), 2))) % mod;
		f[u][1] = (f[u][1] + mul(f[v][1], mul(twos[edges[u]], 2))) % mod;
	}
}

signed main()
{
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	memset(h, -1, sizeof h);
	memset(H, -1, sizeof H);
	twos[0] = 1;
	for (int i = 1; i <= 1e6; i++) twos[i] = mul(twos[i - 1], 2);
	int n = read(), m = read();
	while (m--)
	{
		int a = read(), b = read();
		add(h, e, ne, a, b), add(h, e, ne, b, a);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i, -1);
	for (int i = 1; i <= n; i++)
		for (int j = h[i]; ~j; j = ne[j])
		{
			int k = e[j];
			if (id[i] == id[k])
			{
				edges[id[i]]++;
				continue;
			}
			add(H, E, NE, id[i], id[k]), add(H, E, NE, id[k], id[i]);
		}
	for (int i = 1; i <= cnt; i++)
		edges[i] >>= 1;
	dfs1(1, 0);
	memset(vis, 0, sizeof vis);
	dfs2(1, 0);
	printf("%d\n", f[1][1]);
	return 0;
}