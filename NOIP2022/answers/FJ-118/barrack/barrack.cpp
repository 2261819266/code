#include <bits/stdc++.h>
const int N = 5e5, Mod = (int)1e9 + 7;
int add(int x, int y) { return x + y < Mod ? x + y : x + y - Mod; }
int del(int x, int y) { return x - y < 0 ? x - y + Mod : x - y; }
int qpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1ll * ans * x % Mod;
		x = 1ll * x * x % Mod, y >>= 1;
	}
	return ans;
}
int n, m, fa[N + 10];
std::vector<int> v[N + 10], sn[N + 10];
int dfn[N + 10], low[N + 10], ind, sta[N + 10], top;
int ins[N + 10], isd[N + 10];
void tarjan(int x, int ff) {
	fa[x] = ff, dfn[x] = low[x] = ++ind, sta[++top] = x, ins[x] = 1;
	for (auto i : v[x]) if (i != ff) {
		if (!dfn[i]) tarjan(i, x), low[x] = std::min(low[x], low[i]);
		else if (ins[i]) low[x] = std::min(low[x], dfn[i]);
	}
	if (low[x] >= dfn[x]) isd[x] = 1;
}
int f[N + 10][4], pre[N + 10], suf0[N + 10], suf1[N + 10];
bool vis[N + 10];
void dfs(int x) {
	vis[x] = 1, f[x][0] = f[x][2] = 2, f[x][1] = 1, f[x][3] = 1;
	int tmp = 0;
	for (auto i : v[x]) if (!vis[i]) {
		dfs(i), f[x][0] = 1ll * f[x][0] * f[i][0] % Mod, f[x][2] = 1ll * f[x][2] * f[i][2] % Mod;
		f[x][1] = 1ll * f[x][1] * add(f[i][2], f[i][3]) % Mod;
		f[x][3] = 1ll * f[x][3] * add(f[i][2], f[i][3]) % Mod;
		pre[tmp] = f[i][2];
		if (tmp) pre[tmp] = 1ll * pre[tmp] * pre[tmp - 1] % Mod;
		tmp++, sn[x].push_back(i);
	}
	int sz = tmp;
	for (int p = sn[x].size() - 1; ~p; p--) {
		int i = sn[x][p];
		tmp--, suf1[tmp] = add(f[i][2], f[i][3]), suf0[tmp] = f[i][2];
		if (tmp < sz - 1) suf1[tmp] = 1ll * suf1[tmp] * suf1[tmp + 1] % Mod, suf0[tmp] = 1ll * suf0[tmp] * suf0[tmp + 1] % Mod;
	}
	for (auto i : sn[x]) {
		int tt = 1;
		if (tmp) tt = pre[tmp - 1];
		if (tmp < sz - 1) tt = 1ll * tt * add(1ll * del(suf1[tmp + 1], suf0[tmp + 1]) * f[i][3] % Mod, 1ll * f[i][1] * suf0[tmp + 1] % Mod) % Mod;
		else tt = 1ll * tt * f[i][1] % Mod;
		f[x][1] = add(f[x][1], tt);
		tt = 1;
		if (tmp) tt = pre[tmp - 1];
		if (tmp < sz - 1) tt = 1ll * tt * suf1[tmp + 1] % Mod * f[i][3] % Mod;
		else tt = 1ll * tt * f[i][3] % Mod;
		f[x][3] = add(f[x][3], tt);
		tmp++;
	}
	f[x][1] = 2ll * f[x][1] % Mod;
	f[x][3] = (2ll - isd[x]) * f[x][3] % Mod;
}
int main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1, x, y; i <= m; i++) scanf("%d%d", &x, &y), v[x].push_back(y), v[y].push_back(x);
	tarjan(1, 0), dfs(1);
	printf("%lld\n", 1ll * f[1][1] * qpow(2, Mod - 2) % Mod * qpow(2, m - n + 1) % Mod);
	return 0;
}

