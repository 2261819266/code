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

int dfs(int root) {
    if (!~head[root]) return 0x7fffffff;
    int ans = 0;
    for (int i = head[root]; ~i; i = edge[i].next) {
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
    }
    printf("%d", dfs(r));
}