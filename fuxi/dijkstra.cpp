#include <cstdio>

const int N = 10;
const int M = 10;
const int inf = 1073741823;

int e, bg[N], nx[M], to[M], wt[M];
inline void link(int u, int v, int w) {
	to[++e] = v;
	nx[e] = bg[u];
	wt[e] = w;
	bg[u] = e;
}

int n, m, u, v, w;
int f[N], h[N << 1];                                                    

void update(int x, int y) {
	x += n - 1;
	for (h[x] = y; x; x >>= 1)
		h[x >> 1] = f[h[x]] < f[h[x ^ 1]] ? h[x] : h[x ^ 1];
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i != m; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		link(u, v, w);
	}
	int nn = n << 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j != nn; ++j)
			h[j] = 0;
		for (int j = 0; j <= n; ++j)
			f[j] = inf;
		f[i] = 0;
		update(i, i);
		for (int j = i; true; j = h[1]) {
			if (f[j] == inf)
				break;
			for (int k = bg[j]; k; k = nx[k]) {
				if (f[j] + wt[k] < f[to[k]]) {
					f[to[k]] = f[j] + wt[k];
					update(to[k], to[k]);
				}
			}
			update(j, 0);
		}
		for (int j = 1; j <= n; ++j)
			printf("%d%c", f[j], "\n "[j != n]);
	}
	return 0;
}
