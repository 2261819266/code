#include <cstdio>
#include <cstring>
#include <cmath>

const int maxn = 1e6 + 8, maxl = 20;

int n, m, root, cnt = 0, head[maxn], d[maxn], fa[maxn], a[maxn][maxl], l;
struct E {
	int to, next;
} edge[maxn << 2];

void addEdge(int u, int v) {
	edge[cnt] = (E) {v, head[u]};
	head[u] = cnt++;
}

void dfs(int root, int depth = 1) {
	d[root] = depth;
	for (int i = head[root]; ~i; i = edge[i].next) {
		if (!d[edge[i].to]) dfs(edge[i].to, depth + 1);
	}
}

void getFather(int root) {
	for (int i = head[root]; ~i; i = edge[i].next) {
		if (!fa[edge[i].to]) fa[edge[i].to] = root, getFather(edge[i].to);
	}
}

void geta(int m) {
	for (int i = 0; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 0) a[j][i] = fa[j];
			else a[j][i] = a[a[j][i - 1]][i - 1];
		}
	}
}

int getLCA(int u, int v) {
	if (d[u] < d[v]) return getLCA(v, u);
	for (int i = l; i >= 0; i--) {
		if (d[a[u][i]] >= d[v] && d[u]) u = a[u][i];
	}
	if (u == v) return u;
	for (int i = l; i >= 0; i--) {
		if (a[u][i] != a[v][i]) u = a[u][i], v = a[v][i];
	}
	return fa[u];
}

int main() {
#ifdef LOCAL
	LOCALfo
#endif
	memset(head, -1, sizeof(head));
	scanf("%d%d%d", &n, &m, &root);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		addEdge(u, v);
		addEdge(v, u);
	}
	dfs(root);
	fa[root] = root;
	getFather(root);
	l = log2(n) + 1;
	geta(l);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d\n", getLCA(u, v));
	}
}
