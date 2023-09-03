#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

#define fo(x) freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout);
#define ll long long
#define d(x) maxn + low[i]

using std::vector;
using std::min;
using std::queue;
const int maxn = 1e6 + 8;
const int M = 1e9 + 7;
ll ann[maxn];
int col[maxn], num[maxn];
vector<int> e[maxn * 2], E[maxn];
vector<vector<int> > dis;


int n, m, dfn[maxn], vis[maxn], low[maxn], cnt = 1, fa[maxn];

void dfs1(int u = 1) {
//	vis[u] = true;
	low[u] = dfn[u];
	for (int v : e[u]) {
		if (dfn[v]) {
			if (v != fa[u]) low[u] = min(low[u], low[v]);
			continue;
		}
		dfn[v] = ++cnt;
		fa[v] = u;
		dfs1(v);
		low[u] = min(low[u], low[v]);
	}
//	vis[u] = false;
}

void dfs2(int u = 1) {
	vis[u] = true;
	for (int v : e[u]) {
		if (!vis[v]) dfs2(v);
	}
	int i;
//	for (i = u; low[i] != i; i = low[i]);
	low[u] = low[low[u]];
}

void addedge(int u, int v) {
	e[u].push_back(v);
	e[v].push_back(u);
}

void addEdge(int u, int v) {
	E[u].push_back(v);
//	E[v].push_back(u);
}

void bfs(int u, vector<int> &dis) {
	queue<int> q;
	dis[u] = 0;
	q.push(u);
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		for (int i : E[p]) {
			if (dis[i] == 1) continue;
			dis[i] = dis[p] + 1;
			q.push(i);
		}
	}
	dis[u] = 0;
}

int pow[maxn];
void initpow() {
	pow[0] = 1;
	for (int i = 1; i < m; i++) {
		pow[i] = pow[i - 1] * 2;
		pow[i] %= M;
	}
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	dfn[1] = 1;
	dfs1(1);
	dfs2(1);
//	for (int i : e[8]) printf("%d ", i);
//	putchar(10);
//	for (int i = 1; i <= n; i++) {
//		printf("%d ", low[i]);
//	}
	dis.assign(1, {});
	for (int i = 1; i <= n; i++) {
		int l = low[i];
		if (col[l]) num[col[l]]++;
		else col[l] = dis.size(), dis.push_back({}), num[col[l]] = 1;
	}
	int ms = dis.size();
	for (int i = 0; i < ms; i++) {
		dis[i].assign(ms, 0);
	}
	for (int i = 1; i <= n; i++) {
		for (int j : e[i]) {
			if (low[i] != low[j]) {
				dis[col[low[i]]][col[low[i]]] = 1;
				addEdge(col[low[i]], col[low[j]]);
			}
		}
	}
	for (int i = 1; i < ms; i++) {
		bfs(i, dis[i]);
		for (int j = 1; j < ms; j++) {
			printf("%d", dis[i][j]);
		}
		putchar(10);
	}
	ll ans = pow[m] * n;
	
}



int main() {
	fo(barrack)
//	freopen("con", "w", stdout);
	solve();
	return 0;
}

