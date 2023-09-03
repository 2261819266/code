#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define f(x, y, z) for (int x = y, __ = z; x < __; ++x)

const int maxn = 1e5 + 8, maxm = 5e5 + 8;
int dis[maxn], head[maxn], cnt, vis[maxn];
struct E {
    int to, w, next;
} edge[maxm << 1];
struct Node {
    int u, dis;
    bool operator<(const Node &y) const { return dis > y.dis; }
};
std::priority_queue<Node> q;

void addEdge(int u, int v, int w) {
    edge[cnt] = {v, w, head[u]};
    head[u] = cnt++;
}

void dijkstra(int n, int s) {
    f(i, 1, n + 1) dis[i] = 0x7fffffff;
    dis[s] = 0;
    q.push({s, 0});
    while (!q.empty()) {
        int u = q.top().u;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; ~i; i = edge[i].next) {
            int to = edge[i].to;
            dis[to] = std::min(dis[to], dis[u] + edge[i].w);
            q.push({to, dis[to]});
        }
    }
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    memset(head, -1, sizeof(head));
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