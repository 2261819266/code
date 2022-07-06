#include <cstdio>

const int maxn = 150;

int fa[maxn], root, depth[maxn];

int getDepth(int x) {
	if (x == root)
		return 1;
	if (!depth[x])
		depth[x] = getDepth(fa[x]) + 1;
	return depth[x];
}

int getLca(int u, int v) {
	if (u == v)
		return u;
	int n1 = getDepth(u), n2 = getDepth(v);
	if (n1 < n2)
		return getLca(v, u);
	return getLca(fa[u], v);
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif

	int n, m;
	scanf("%d%d%d", &n, &m, &root);
	fa[root] = -1;
	for (int c = 1; c < n; c++) {
		int u, v;
		scanf("%d%d", &u, &v);
		fa[u] = v;
	}
	for (int c = 1; c <= m; c++) {
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d\n", getLca(u, v));
	}
}