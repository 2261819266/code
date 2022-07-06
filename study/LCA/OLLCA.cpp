#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 1e6 + 9;
int to[maxn << 2], next[maxn << 2], head[maxn], top, a[maxn << 2], d[maxn];

void addEdge(int u, int v) {
	to[top] = v, next[top] = head[u], head[u] = top++;
}

int dfs(int root, int *data = a, int pre = 0, int k = 1) {
	d[root] = k;
	*data = root;
	int *p = data + 1;
	for (int i = head[root]; ~i; i = next[i]) {
		if (to[i] != pre) 
			p += dfs(to[i], p, root, k + 1), p[0] = root, p++;
	}
	return p - data;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	LOCALfo
#endif
	int n, m, root;
	memset(head, -1, sizeof(head));
	scanf("%d%d%d", &n, &m, &root);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		addEdge(u, v) , addEdge(v, u);
	}
	dfs(root);
	
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		int l, r, k = 0;
		for (int i = 0; a[i]; i++) {
			if (a[i] == u) l = i;
			if (a[i] == v) r = i;
		}
		if (l > r) std::swap(l, r);
		k = l;
		for (int i = l; i <= r; i++) {
			if (d[a[i]] < d[a[k]]) k = i;
		}
		printf("%d\n", a[k]);
	}
	return 0;
}