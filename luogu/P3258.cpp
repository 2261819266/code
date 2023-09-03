#include <cstdio>
#include <cstring>
#include <vector>

const int maxn = 3e5 + 8;
int a[maxn];
std::vector<int> e[maxn];
int n;
int fa[maxn], dep[maxn], son[maxn], size[maxn];
int top[maxn], w[maxn], ans[maxn];

void dfs1(int u) {
    size[u] = 1;
    for (auto v : e[u]) {
        if (dep[v]) continue;
        dep[v] = dep[u] + 1;
        fa[v] = u;
        dfs1(v);
        size[u] += size[v];
    }
}

void dfs2(int u, int t) {
    top[u] = t;
    int x = 0;
    for (auto v : e[u]) {
        if (size[v] > size[x] && dep[v] > dep[u]) 
            x = v;
    }
    son[u] = x;
    if (x) dfs2(x, t);
    for (auto v : e[u]) {
        if (x != v && dep[v] > dep[u]) 
            dfs2(v, v);
    }
}

void getPath(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) 
            std::swap(u, v);
        w[son[u]]--;
        u = top[u];
        w[u]++;
        u = fa[u];
    }
    if (dep[u] < dep[v]) std::swap(u, v);
    w[son[u]]--;
    w[v]++;
}

void dfs3(int u, int x = 0) {
    ans[u] = w[u] + x;
    if (son[u]) {
        dfs3(son[u], ans[u]);
    }
    for (auto v : e[u]) {
        if (dep[v] > dep[u] && v != son[u]) {
            dfs3(v);
        }
    }
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    fa[1] = 1;
    dep[1] = 1;
    dfs1(1);
    dfs2(1, 1);
    for (int i = 1; i < n; i++) {
        getPath(a[i], a[i + 1]);
    }
    dfs3(1);
    ans[a[1]]++;
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i] - 1);
    }
}