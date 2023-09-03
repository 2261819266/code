#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

const int maxn = 3e3 + 8, maxm = 6e3 + 8, inf = 0x3f3f3f3f;
struct E {
    int to, w, ww;
};
std::vector<E> e[maxn];
int dis[maxn], vis[maxn], d[maxn];

struct Node {
    int u, dis;
    bool operator<(const Node &b) const {
        return dis > b.dis;
    }
};

bool BF(int n, int s) {
    memset(dis, 0x3f, sizeof(dis));
    bool flag;
    for (int i = 1; i <= n; i++) {
        flag = false;
        dis[s] = 0;
        for (int u = 0; u <= n; u++) {
            if (dis[u] == inf) continue;
            for (auto j : e[u]) {
                int v = j.to, w = j.w;
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    flag = true;
                }
            }
        }
    }
    return flag;
}

void dijkstra(int n, int s) {
    const int inf = 1e9;
    for (int i = 1; i <= n; i++) {
        dis[i] = d[i] = inf;    
        vis[i] = false;
    }
    std::priority_queue<Node> q;
    q.push({s});
    dis[s] = d[s] = 0;
    while (!q.empty()) {
        int u = q.top().u;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto j : e[u]) {
            int v = j.to, w = j.w, ww = j.ww;
            if (d[v] > d[u] + ww) {
                d[v] = d[u] + ww;
                dis[v] = dis[u] + w;
                q.push({v, d[v]});
            }
        }
    }
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back({v, w});
    }
    for (int i = 1; i <= n; i++) {
        e[0].push_back({i, 0});
    }
    bool k = BF(n, 0);
    if (k) {
        printf("-1");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (auto &j : e[i]) {
            int v = j.to, w = j.w;
            j.ww = w + dis[i] - dis[v];
            // printf("%d %d %d\n", i, v, j.ww);
        }
    }
    for (int s = 1; s <= n; s++) {
        dijkstra(n, s);
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += (long long)dis[i] * i;
        }
        // putchar('\n');
        printf("%lld\n", ans);
    }
}