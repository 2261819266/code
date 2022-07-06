#include <cstdio>
#include <cstring>
#define swap(X, Y) X ^= Y ^= X ^= Y
#define min(X, Y) (X) < (Y) ? (X) : (Y)

const int maxm = 105, maxn = 105;
struct E {
	int to, next;
} edge[maxm * 4];

int head[maxn], top;

void init() { memset(head, -1, sizeof(head)), top = 0; }

void addedge1(int u, int v) {
	edge[top] = (E){v, head[u]};
	head[u] = top++;
}

void addedge(int u, int v) {
	addedge1(u, v);
	addedge1(v, u);
}

int fa[maxn], root, depth[maxn];

bool k[maxn];
void EToTree(int x) {
	k[x] = true;
	for (int c = head[x]; c != -1; c = edge[c].next) {
		if (!k[edge[c].to]) {
			fa[edge[c].to] = x;
			EToTree(edge[c].to);
		}
	}
}

int d[maxn], topd;
bool k2[maxn], k3[maxn];

void dfs(int x, int k) {
	k2[x] = true;
	depth[x] = k;
	for (int c = head[x]; c != -1; c = edge[c].next) {
		int s = edge[c].to;
		if (!k2[s])
			dfs(s, k + 1);
	}
}

void dfs(int x) {
	d[topd++] = x;
	k3[x] = true;
	for (int c = head[x]; c != -1; c = edge[c].next) {
		int s = edge[c].to;
		if (!k3[s])
			dfs(s), d[topd++] = x;
	}
}

int getLCA(int u, int v) {
	int c, e;
	for (c = 0; c < topd; c++) {
		if (d[c] == u) {
			break;
		}
	}
	for (e = 0; e < topd; e++) {
		if (d[e] == v)
			break;
	}
	if (e < c)
		swap(c, e);
	int minn = maxn;
	for (int f = c; f <= e; f++) {
		minn = min(depth[f], minn);
	}
	return minn;
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif

	int n, m;
	scanf("%d%d%d", &n, &m, &root);
	init();
	fa[root] = -1;
	for (int c = 1; c < n; c++) {
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	dfs(root, 1);
	dfs(root);
	for (int c = 1; c <= n; c++) {
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d\n", getLCA(u, v));
	}
}