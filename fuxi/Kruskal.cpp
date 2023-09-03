#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 6000, maxm = 1e6;
struct E {
	int u, v, w;
} edge[maxm];
int fa[maxn], n, m;

inline void init(int n) {
	for (int c = 1; c <= n; c++) {
		fa[c] = c;
	}
}

inline void read() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	init(n);
	for (int c = 0; c < m; c++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		if (u > v)
			std::swap(u, v);
		edge[c] = E{u, v, w};
	}
}

inline bool cmp(const E &x, const E &y) { return x.w < y.w; }

inline int findfather(int x) {
	if (fa[x] != x)
		fa[x] = findfather(fa[x]);
	return fa[x];
}

int solve() {
	std::sort(edge, edge + m, cmp);
	int ans = 0;
	for (int c = 0; c < m; c++) {
		E *k = edge + c;
		int u = k->u, v = k->v, w = k->w;
		if (findfather(u) != findfather(v)) {
			fa[fa[v]] = u;
			ans += w;
		}
	}
	int k = -1;
	for (int c = 1; c <= n; c++) {
		if (findfather(c) == c)
			k++;
	}
	return k ? -1 : ans;
}

int main(int argc, char const *argv[]) {
	read();
	int x = solve();
	printf(x >= 0 ? "%d" : "orz", x);
	return 0;
}
