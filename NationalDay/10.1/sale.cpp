#include <cstdio>
#include <cstring>
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))

const int maxn = 1000000;
struct E {
	int to, w, p, next;
} edge[maxn];
int head[maxn], top;

void init() { memset(head, -1, sizeof(head)), top = 0; }

void addedge(int u, int v, int w, int p) { edge[top] = (E){v, w, p, head[u]}, head[u] = top++; }

bool k[maxn], k1[maxn];
int dfs(int x, int y) {
	if (head[x] == -1)
		return 0x7fffffff;
	k1[x] = true;
	int minx = 0x7fffffff;
	for (int c = head[x]; c != -1; c = edge[c].next) {
		E d = edge[c];
		if (k1[d.to])
			minx = min(minx, d.w - y);
		else {
			minx = min(minx, max(dfs(d.to, d.p + y), d.w - y));
		}
	}
	// k1[x] = false;
	return minx;
}

int dfs(int x) {
	if (head[x] == -1)
		return 0x7fffffff;
	k1[x] = true;
	int minx = 0x7fffffff;
	for (int c = head[x]; c != -1; c = edge[c].next) {
		E d = edge[c];
		if (k1[d.to])
			minx = min(minx, d.w);
		else {
			minx = min(minx, max(dfs(d.to), d.w));
		}
	}
	k1[x] = false;
	return minx;
}

int main() {
#ifdef LOCAL
	LOCALfo
#endif
	// freopen("sale.in", "r", stdin);
	// freopen("sale.out", "w", stdout);
	// printf("2 3 3 1 -1\n");
	int n, m, kk = 0;
	init();
	scanf("%d%d", &n, &m);
	for (int c = 0; c < m; c++) {
		int u, v, w, p;
		scanf("%d%d%d%d", &u, &v, &w, &p);
		addedge(u, v, w, p);
		if (p > 0)
			kk++;
	}
	for (int c = 1; c <= n; c++) {
		int y = kk > 0 ? dfs(c, 0) : dfs(c);
		printf("%d ", y == 0x7fffffff ? -1 : y);
	}
}