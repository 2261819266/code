#include <bits/stdc++.h>

const int N = 30 + 5;

int n, m;

int U[N], V[N];

int p[N], vis[N], to[N][N], f[N][N];

bool check(int K) {
	for (int i = 1; i <= n; ++ i) {
		f[i][i] = 1;
		for (int j = 1; j <= n; ++ j) {
			if (i != j) f[i][j] = to[i][j];
		}
	}

	for (int k = 1; k <= n; ++ k)
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				f[i][j] |= (f[i][k] & f[k][j]);
				
	for (int i = 1; i <= K; ++ i) {
		for (int j = 1; j <= K; ++ j) {
			if (i != j && f[p[i]][p[j]] == 0) {
				return 0;
			}
		}
	}
	return 1;
}

int ans = 0;

void dfs2(int u, int k) {
	if (u == m) {
		if (check(k)) 
			ans ++;
		
		return;
	}
	to[U[u + 1]][V[u + 1]] = to[V[u + 1]][U[u + 1]] = 1;
	dfs2(u + 1, k);
	to[U[u + 1]][V[u + 1]] = to[V[u + 1]][U[u + 1]] = 0;
	dfs2(u + 1, k);
}

void dfs1(int u, int cho) {
	if (u == n) {
		if (cho == 0) return;
		dfs2(0, cho);
		return;
	}
	p[cho + 1] = u + 1;
	dfs1(u + 1, cho + 1);
	p[cho + 1] = 0;
	dfs1(u + 1, cho);
}

int main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= m; ++ i)
		scanf("%d%d", &U[i], &V[i]);
	
	dfs1(0, 0);
	
	printf("%d\n", ans);
	return 0;
}
