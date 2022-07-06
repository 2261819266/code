#include <cstdio>
#include <algorithm>
#include <cstring>

const int maxn = 1e6 + 9, maxl = 20;

int n, m, root;
struct E {
	int v, next;	
} edge[maxn << 3];

int head[maxn], top, a[maxn][maxl], d[maxn];

void addEdge(int u, int v) {
	edge[top] = (E){v, head[u]}, head[u] = top++;
	edge[top] = (E){u, head[v]}, head[v] = top++;
}

void buildTree(int root, int k = 1) {
	d[root] = k;
	for (int i = head[root]; i != -1; i = edge[i].next) {
		if (edge[i].v != a[root][0])
			a[edge[i].v][0] = root, buildTree(edge[i].v, k + 1);
	}
}

int getLca(int u, int v) {
	if (u == root || v == root) return root;
	if (d[u] < d[v]) std::swap(u, v);
	int i;
	if (d[u] != d[v]) {
		for (i = maxl - 1; i >= 0; i--)
			if (d[a[u][i]] >= d[v])
				u = a[u][i];
		// u = a[u][0];
	}
	if (u == v) return u;
	for (i = maxl - 1; i >= 0; i--) {
		if (a[u][i] != a[v][i])
			u = a[u][i], v = a[v][i];
	}
	return a[u][0];
}

int main() {
#ifdef LOCAL
	LOCALfo
#endif
	scanf("%d%d%d", &n, &m, &root);
	memset(head, -1, sizeof(head));
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		addEdge(u, v);
	}
	a[root][0] = root;
	buildTree(root);
	// for (int i = 1; i <= n; i++) printf("%d\n", d[i]);
	for (int i = 1; i < maxl; i++) {
		for (int j = 1; j <= n; j++) {
			a[j][i] = a[a[j][i - 1]][i - 1];
		}
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d\n", getLca(u, v));
	}
	return 0;
}