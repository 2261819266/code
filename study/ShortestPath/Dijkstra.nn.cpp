#include <cstdio>
#include <cstring>
#include <algorithm>
#define f(x, y, z) for (auto x = y, __ = z; x < z; ++x) 

const int maxn = 1e4 + 8, maxm = 5e5 + 8;
struct E {
    int to, w, next;
} edge[maxm << 2];
int head[maxn], cnt;

void addEdge(int u, int v, int w) {
    edge[cnt] = (E) {v, w, head[u]};
    head[u] = cnt++;
}

int dis[maxn], vis[maxn];

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
    f(i, 1, n + 1) dis[i] = 0x7fffffff;
    dis[s] = 0;
    f(i, 0, n) {
        int u, minx = 0x7fffffff;
        f(j, 1, n + 1) {
            if (minx > dis[j] && !vis[j]) u = j, minx = dis[j];
        }
        vis[u] = true;
        for (auto j = head[u]; ~j; j = edge[j].next) {
            int to = edge[j].to;
            dis[to] = std::min(dis[to], dis[u] + edge[j].w);
        }
    }
    f(i, 1, n + 1) printf("%d ", dis[i]);
}
