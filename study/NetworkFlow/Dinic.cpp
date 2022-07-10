#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define ll long long
#define f(x, y, z) for (auto x = y, __ = z; x < __; ++x)

const int maxn = 300, maxm = 5e3 + 8;
struct E {
    int to, next;
} edge[maxm << 2];
int head[maxn], cnt, dep[maxn];
ll a[maxn][maxn];
int n, m, s, t;

void addEdge(int u, int v, ll w) {
    if (!cnt) memset(head, -1, sizeof(head));
    edge[cnt] = {v, head[u]};
    head[u] = cnt++;
    a[u][v] += w;
}

bool bfs() {
    memset(dep, 0x3f, sizeof(dep));
    std::queue<int> q;
    q.push(s);
    dep[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = edge[i].next) {
            int to = edge[i].to;
            if (dep[to] > dep[u] + 1 && a[u][to]) dep[to] = dep[u] + 1, q.push(to);
        }
    }
    return dep[t] != 0x3f3f3f3f;
}

ll dfs(int u, ll minx) {
    ll ans = 0;
    if (u == t) return minx;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int to = edge[i].to;
        if (dep[to] == dep[u] + 1) {
            if (ans = dfs(to, std::min(a[u][to], minx))) {
                a[u][to] -= ans;
                a[to][u] += ans;
                return ans;
            }
        }
    }
    return 0;
}

ll Dinic() {
    ll ans = 0, x = 0;
    while (bfs()) {
        while (x = dfs(s, 1ll << 60)) ans += x;
    }
    return ans;
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif  
    scanf("%d%d%d%d", &n, &m, &s, &t);
    f(i, 0, m) {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, 0);
    }
    printf("%lld", Dinic());
}
