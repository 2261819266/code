#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

const int maxn = 2e5 + 8;
struct Edge { int v, w; };
struct Node {
    int u, dis;
    bool operator<(const Node &b) const {
        return dis > b.dis;
    }
};
std::vector<Edge> e[maxn];
int dis[maxn], vis[maxn];

void Dijkstra(int s) {
    memset(dis, 0x3f, sizeof(dis));
    std::priority_queue<Node> q;
    dis[s] = 0;
    q.push({s, 0});
    while (!q.empty()) {
        int u = q.top().u;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto n : e[u]) {
            int v = n.v;
            dis[v] = std::min(dis[v], n.w + dis[u]);
            q.push({v, dis[v]});
        }
    }
}

void P4779() {
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back({v, w});
    }
    Dijkstra(s);
    for (int i = 1; i <= n; i++) {
        printf("%d ", dis[i]);
    }
}

int main() {
    P4779();
}