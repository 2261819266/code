#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define f(x, y, z) for (int x = y, __ = z; x < z; ++x)

const int maxn = 1e5 + 8, maxm = 2e5 + 8;
std::priority_queue<int, std::vector<int>, std::greater<int>> q;
int dis[maxn], head[maxn], cnt, vis[maxn];
struct E {
    int to, w, next;
} edge[maxn << 2];

void addEdge(int u, int v, int w) {
    if (!cnt) memset(head, -1, sizeof(head));
    edge[cnt] = {v, w, head[u]};
    head[u] = cnt++;
}

void dijkstra(int n, int s) {
    f(i, 1, n + 1) dis[i] = 0x7fffffff;
    dis[s] = 0;
    q.push(s);
    f(i, 0, n) {
        int u = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; ~i; i = edge[i].next) {
            int to = edge[i].to;
            dis[to] = std::min(dis[to], dis[u] + edge[i].w);
            q.push(to);
        }
    }
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);
    f(i, 0, m) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
    }
    dijkstra(n, s);
    f(i, 1, n + 1) printf("%d ", dis[i]);
}