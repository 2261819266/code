#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using std::queue;

const int maxn = 105, maxm = maxn * maxn;
int n, m, a[maxn], b[maxn], top, head[maxn], vis[maxn], out[maxn];
queue<int> q;

struct E {
	int to, w, next;
} edge[maxm];

void init() { memset(head, -1, sizeof(head)); }

void addedge(int u, int v, int w) {
	edge[top] = E{v, w, head[u]};
	head[u] = top++;
	out[u]++;
}

void read() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	init();
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", a + i, b + i);
		if (a[i])
			q.push(i);
	}
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		addedge(u, v, w);
	}
}

void solve() {
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (a[u] <= 0)
			continue;
		for (int i = head[u]; ~i; i = edge[i].next) {
			E *y = &edge[i];
			int v = y->to;
			int w = y->w;
			a[v] += a[u] * w;
			if (!vis[v]) {
				vis[v] = true;
				q.push(v);
				a[v] -= b[v];
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!out[i] && a[i] > 0)
			ans++, printf("%d %d\n", i, a[i]);
	}
	if (!ans)
		printf("NULL");
}

int main(int argc, char const *argv[]) {
	read();
	solve();
	return 0;
}
