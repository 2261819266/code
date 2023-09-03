#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5, M = 1e6 + 5, P = 1e9 + 7, I2 = (P + 1) / 2;

int pw[M];
vector<int> G[N];
int dfn[N], low[N], inS[N], tot;
stack<int> S;
int wh[N], siz[N];

void Tarjan(int x, int fa = -1)
{
	dfn[x] = low[x] = ++tot;
	S.push(x);
	inS[x] = 1;
	for (int i = 0; i < G[x].size(); ++i) {
		int v = G[x][i];
		if (v == fa) {
			continue;
		}
		if (!dfn[v]) {
			Tarjan(v, x);
			low[x] = min(low[x], low[v]);
		} else if (inS[v]) {
			low[x] = min(low[x], dfn[v]);
		}
	}
	if (dfn[x] == low[x]) {
		++wh[0];
		int v;
		do {
			v = S.top();
			S.pop();
			inS[v] = 0;
			wh[v] = wh[0];
			++siz[wh[v]];
		} while (v != x);
	}
	return;
}

vector<int> nG[N];
int f[N], g[N], A;

void dfs(int x, int fa = -1)
{
	for (int i = 0; i < nG[x].size(); ++i)  {
		int v = nG[x][i];
		if (v == fa) {
			continue;
		}
		dfs(v, x);
		g[x] = (g[x] + 1ll * (f[v] + g[v]) * I2 % P * (f[x] + g[x])) % P;
		f[x] = (f[x] + 1ll * (f[v] + g[v]) * I2) % P;
	}
	g[x] = (g[x] + 1ll * (pw[siz[x]] - 1) * (f[x] + g[x] + 1)) % P;
	((A += g[x]) >= P) && (A -= P);
	return;
}

signed main()
{
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	pw[0] = 1;
	for (int i = 1; i <= max(n, m); ++i) {
		pw[i] = 2ll * pw[i - 1] % P;
	}
	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	Tarjan(1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < G[i].size(); ++j) {
			int v = G[i][j];
			if (wh[i] != wh[v]) {
				nG[wh[i]].push_back(wh[v]);
			}
		}
	}
	for (int i = 1; i <= wh[0]; ++i) {
		sort(nG[i].begin(), nG[i].end());
		nG[i].erase(unique(nG[i].begin(), nG[i].end()), nG[i].end());
	}
	dfs(1);
	printf("%lld\n", 1ll * (A % P + P) % P * pw[m] % P);
	return 0;
}
