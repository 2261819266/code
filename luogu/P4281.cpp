#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>

const int maxn = 5e5 + 8;
std::vector<int> e[maxn];
int fa[maxn], dep[maxn], size[maxn], top[maxn];
int n, m;

void dfs1(int u = 1) {
    size[u] = 1;
    for (int v : e[u]) {
        if (dep[v]) continue;
        dep[v] = dep[u] + 1;
        fa[v] = u;
        dfs1(v);
        size[u] += size[v];
    }
}

void dfs2(int u = 1, int t = 1) {
    top[u] = t;
    int x = 0;
    for (int v : e[u]) {
        if (fa[v] == u && size[v] > size[x]) 
            x = v;
    }
    if (x) dfs2(x, t);
    for (int v : e[u]) { 
        if (fa[v] == u && v != x) 
            dfs2(v, v);
    }
}

int getPath(int u, int v) {
    int ans = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]])
            std::swap(u, v);
        ans += dep[u];
        u = fa[top[u]];
        ans -= dep[u];
    }
    return ans + abs(dep[u] - dep[v]);
}

int getLCA(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]])
            std::swap(u, v);
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dep[1] = 1;
    fa[1] = 1;
    dfs1();
    dfs2();
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        int p, c = 0;
        int l[3] = {getLCA(x, y), getLCA(x, z), getLCA(y, z)};
        std::sort(l, l + 3, [] (int x, int y) { return dep[x] < dep[y]; });
        c = getPath(x, y) + getPath(x, z) + getPath(y, z);
        p = l[2];
        printf("%d %d\n", p, c / 2);
    }
}
