#include <cstdio>
#include <cstring>

const int maxn = 5e3 + 8, maxm = 5e5 + 8, B = 80112002;
struct E {
    int to, next;
} edge[maxm];
int head[maxn], cnt = 0, producer, dp[maxn];
bool consumer[maxn];

void addedge(int u, int v) {
    edge[cnt] = (E) {v, head[u]};
    head[u] = cnt++;
}

void init() { memset(head, -1, sizeof(head)); }

int dfs(int x) {
    if (dp[x]) return dp[x];
    if (head[x] < 0) return dp[x] = 1;
    for (int i = head[x]; ~i; i = edge[i].next) {
        dp[x] += dfs(edge[i].to);
        dp[x] %= B;
    }
    return dp[x];
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    init();
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addedge(u, v);
        consumer[v] = true;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        dfs(i);
        if (!consumer[i]) {
            ans += dfs(i);
            ans %= B;
        }
    }
    printf("%d", ans);
}