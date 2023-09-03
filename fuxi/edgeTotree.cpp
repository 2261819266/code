#include <cstdio>
#include <cstring>

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
	EToTree(root);
	for (int c = 1; c <= n; c++) {
		printf("%d\n", fa[c]);
	}
}