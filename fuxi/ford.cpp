#include <cstdio>
#include <cstring>

const int maxn = 100005, maxm = 1000005;
int dis[maxn], pre[maxn];

struct E {
	int u, v, w;
} edge[maxm * 4];

void init(int s) {
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	pre[s] = 0;
}

void ford(int n, int m, int s) {
	for (int c = 1; c <= m; c++)
		if (edge[c].w && edge[c].u == s)
			dis[edge[c].v] = edge[c].w;
	for (int c = 1; c < n; c++)
		for (int d = 1; d <= m; d++) {
			E *a = &edge[d];
			if (dis[a->u] + a->w < dis[a->v]) {
				dis[a->v] = dis[a->u] + a->w;
				pre[a->v] = a->u;
			}
		}
}

int main() {

#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif

	int n, m, s;
	scanf("%d%d%d", &n, &m, &s);
	init(s);
	for (int c = 1; c <= m; c++) {
		E &a = edge[c];
		scanf("%d%d%d", &a.u, &a.v, &a.w);
	}
	ford(n, m, s);
	for (int c = 1; c <= n; c++)
		printf("%d ", dis[c]);
}