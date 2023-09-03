#include <cstdio>
#include <algorithm>
#include <vector>

const int maxn = 1e5 + 8;
std::vector<int> e[maxn];
int dfn[maxn], col[maxn], cnt, vis[maxn];
int a[maxn];

void dfs(int u, int x) {
    if (a[u]) return;
    a[u] = x;
    for (int v : e[u]) {
        dfs(v, x);
    }
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif      
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[v].push_back(u);
    }
    for (int i = n; i; i--) {
        dfs(i, i);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
}