#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

const int maxn = 1e5 + 8;
struct E {
    int to, w;
};
std::vector<E> e[maxn];
int dep[maxn], fa[maxn], top[maxn], size[maxn], dis[maxn];

void dfs1(int u = 1) {
    size[u] = 1;
    for (auto i : e[u]) {
        int v =  i.to;
        if (dep[v]) continue;
        dep[v] = dep[u] + 1;
        fa[v] = u;
        dfs1(v);
        size[u] += size[v];
    }
}

void dfs2(int u = 1, int t = 1) {
    top[u] = t;
    int x = 0, w;
    for (auto i : e[u]) {
        int v = i.to;
        if (size[v] > size[x] && dep[v] == dep[u] + 1) x = v, w = i.w;
    }
    if (x)
        dis[x] = dis[u] ^ w, dfs2(x, t);
    for (auto i : e[u]) {
        int v = i.to, w = i.w;
        if (x != v && dep[v] == dep[u] + 1) {
            dis[v] = w;
            dfs2(v, v);
        }
    }
}

int getPath(int u, int v) {
    int ans = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) {
            std::swap(u, v);
        }
        ans ^= dis[u];
        u = fa[top[u]];
    }
    return ans ^ dis[v] ^ dis[u];
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    fa[1] = 1;
    dis[1] = 0;
    dep[1] = 1;
    dfs1();
    dfs2();
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%d\n", getPath(u, v));
    }
}