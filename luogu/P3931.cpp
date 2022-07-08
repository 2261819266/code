#include <cstdio>
#include <algorithm>
#include <cstring>

const int maxn = 1e5 + 8;
struct E {
    int to, w, next;
} edge[maxn];
int head[maxn], cnt;

void addedge(int u, int v, int w) {
    edge[cnt] = (E) {v, w, head[u]};
    head[u] = cnt++;
}

bool vis[maxn];

int dfs(int root) {
    vis[root] = true;
    int ans = 0x7fffffff;
    for (int i = head[root]; ~i; i = edge[i].next) {
        if (vis[edge[i].to]) continue;
        int x = dfs(edge[i].to);
        ans += std::min(x, edge[i].w);
    }
    return ans;
}

int main() {
#ifdef LOCAL    
    LOCALfo
#endif
    int n, r;
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &r);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w);
        addedge(v, u, w);
    }
    printf("%d", dfs(r));
}