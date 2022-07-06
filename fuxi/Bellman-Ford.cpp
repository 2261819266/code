// C++ Version
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
const int maxn = 10005; // C++ Version
struct edge {
	int v, w;
};
using std::queue;
using std::vector;
vector<edge> e[maxn];
int dis[maxn], cnt[maxn], vis[maxn];
queue<int> q;
bool spfa(int n, int s) {
	memset(dis, 63, sizeof(dis));
	dis[s] = 0, vis[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop(), vis[u] = 0;
		for (auto ed : e[u]) {
			int v = ed.v, w = ed.w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				cnt[v] = cnt[u] + 1; // 记录最短路经过的边数
				if (cnt[v] >= n)
					return false;
				// 在不经过负环的情况下，最短路至多经过 n - 1 条边
				// 因此如果经过了多于 n 条边，一定说明经过了负环
				if (!vis[v])
					q.push(v), vis[v] = 1;
			}
		}
	}
	return true;
}
int main(int argc, char const *argv[]) {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	int n, m, s;
	scanf("%d%d%d", &n, &m, &s);
	for (int c = 0; c < m; c++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[u].push_back(edge{v, w});
	}
	spfa(n, s);
	for (int c = 1; c <= n; c++) {
		printf("%d ", dis[c]);
	}
	return 0;
}
