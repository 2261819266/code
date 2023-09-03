#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);
#define f(x, y, z) for (int x = y, __ = z; x < __; ++x)

const int maxn = 2e5 + 8;
struct E {
    int to, next;
} edge[maxn << 2];
int h[maxn], cnt, v[maxn], dp[maxn][2];

void addedge(int u, int v) {
    if (!cnt)
        memset(h, -1, sizeof(h));
    edge[cnt] = { v, h[u] };
    h[u] = cnt++;
}

bool dfs(int x, bool now = 1) {
    // if (!v[x]) return !now;
    if (~dp[x][now])
        return dp[x][now];
    bool ans = false;
    for (int i = h[x]; ~i; i = edge[i].next) {
        int to = edge[i].to;
        if (v[to] < v[x])
            ans |= dfs(to, !now);
    }
    return dp[x][now] = ans ^ now ^ 1;
}

int main() {
    fo(game) int n;
    scanf("%d", &n);
    f(i, 1, n + 1) { scanf("%d", v + i); }
    f(i, 1, n) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (u > v) std::swap(u, v);
        addedge(u,v);
    }
    memset(dp, -1, sizeof(dp));
    f(i, 1, n + 1) {
        if (dfs(i))
            printf("%d ", i);
    }
}