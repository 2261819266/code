#include <cstdio>
#include <cstring>
#define maxn 1005
// #define maxm 1005

int dis[maxn], pre[maxn], a[maxn][maxn];
bool b[maxn];

void init(int s) {
	memset(a, 0x40, sizeof(a));
	memset(dis, 0x40, sizeof(dis));
	dis[s] = 0;
	memset(pre, 0, sizeof(pre));
	memset(b, false, sizeof(b));
	b[s] = true;
}

void dij(int n, int s) {
	for (int c = 1; c <= n; c++)
		dis[c] = a[s][c];
	dis[s] = 0;
	for (int c = 1; c <= n; c++) {
		int minx = dis[0], minadd = 0;
		for (int d = 2; d <= n; d++)
			if (!b[d]) minx > dis[d] ? minx = dis[d], minadd = d : 0;
		b[minadd] = true;
		for (int d = 1; d <= n; d++)
			if (!b[d])
				if (dis[minadd] + a[minadd][d] < dis[d])
					dis[d] = dis[minadd] + a[minadd][d], pre[d] = minadd;
	}
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	int s, n, m;
	scanf("%d%d%d", &n, &m, &s);
	init(s);
	for (int c = 1; c <= m; c++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		a[u][v] = a[v][u] = w;
	}
	dij(n, s);
	for (int c = 1; c <= n; c++)
		if (dis[c] < 0)
			printf("%d\n", 0x7fffffff);
		else
			printf("%d\n", dis[c]);
}
