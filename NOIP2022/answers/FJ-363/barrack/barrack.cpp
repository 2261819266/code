#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e2 + 1;
const int maxm = 1e2 + 1;

struct edge {
	int u, v;
};

int n, m;
edge e[maxm << 1];
int cnt;
int ans;

int g[maxn][maxn];
int s[maxn];

void dfs2(int pos, int step) {
	if (pos == n + 1) {
		if (step == 1) return;
		for (int i = 1; i < step; i++) {
			for (int j = i; j < step; j++) {
				if (!g[s[i]][s[j]]) return;
			}
		}
		++ans;
//		if (ans > 10) return;
//		for (int i = 1; i <= n; i++) {
//			for (int j = i + 1; j <= n; j++) {
//				if (g[i][j]) cout << i << " " << j << endl;
//			}
//		}
//		for (int i = 1; i < step; i++) {
//			cout << s[i] << " ";
//		}
//		cout << endl << endl;
		return;
	}
	dfs2(pos + 1, step);
	s[step] = pos;
	dfs2(pos + 1, step + 1);
	s[step] = 0;
}

void dfs(int pos) {
	if (pos == m + 1) {
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (i == j) continue;
					if (g[i][k] && g[k][j]) g[i][j] = 1;
				} 
			}
		}
		dfs2(1, 1);
		return;
	}
	dfs(pos + 1);
	g[e[pos].u][e[pos].v] = 1;
	g[e[pos].v][e[pos].u] = 1;
	g[e[pos].u][e[pos].u] = 1;
	g[e[pos].v][e[pos].v] = 1;
	dfs(pos + 1);
	g[e[pos].u][e[pos].v] = 0;
	g[e[pos].v][e[pos].u] = 0;
	g[e[pos].u][e[pos].u] = 0;
	g[e[pos].v][e[pos].v] = 0;
}

int main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		e[++cnt].u = u;
		e[cnt].v = v;
	}
	dfs(1);
	cout << ans;
	return 0;
}

