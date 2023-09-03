#include <cstdio>
#include <cstring>
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

const int maxn = 10005, maxm = 100005;

struct E {
	int to, w, next;
	E() { next = -1; }
} edge[maxm*4];
int top, head[maxn], dis[maxn], pre[maxn];
bool b[maxn];

void init() { memset(head, -1, sizeof(head)); }

void addedge(int u, int v, int w) {
	edge[top].to = v;
	edge[top].w = w;
	edge[top].next = head[u];
	head[u] = top++;
}

void dij(int n, int s) {
	memset(b, false, sizeof(b));
	b[s] = true;
	memset(pre, 0, sizeof(pre));
	memset(dis, 0x3f, sizeof(dis));
	for (int c = head[s]; c != -1; c = edge[c].next)
		dis[edge[c].to] = min(dis[edge[c].to], edge[c].w);
	dis[s] = 0;
	for (int c = 1; c <= n; c++) {
		int u = 0, x = 0x7fffffff;
		for (int c = 1; c <= n; c++)
			if (x > dis[c] && !b[c])
				x = dis[c], u = c;
		b[u] = true;
		for (int d = head[u]; d != -1; d = edge[d].next) {
			if (!b[edge[d].to])
				if (dis[u] + edge[d].w < dis[edge[d].to])
					dis[edge[d].to] = dis[u] + edge[d].w, pre[edge[d].to] = u;
		}
	}
}

int main() {

#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	int n, m, s, u, v, w;
	scanf("%d%d%d", &n, &m, &s);
	init();
	for (int c = 0; c < m; c++)
		scanf("%d%d%d", &u, &v, &w), addedge(u, v, w);
	dij(n, s);
	for (int c = 1; c <= n; c++)
		if (dis[c] > 0x30000000)
			printf("%d ", 0x7fffffff);
		else
			printf("%d ", dis[c]);
}