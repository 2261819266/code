#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <stack>
// #include <pa

const int maxn = 1e3 + 8, maxm = 5e5 + 8;
std::vector<int> e[maxn];
int vis[maxn], low[maxn], dfn[maxn], cnt, fa[maxn];
std::vector<std::pair<int, int>> p; 

using std::min;

void tarjan(int u) {
    vis[u] = true;
    dfn[u] = low[u] = ++cnt;
    for (int v : e[u]) {
        if (fa[u] == v) continue;
        if (!dfn[v]) {
            fa[v] = u;
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (vis[v]) {
            low[u] = min(low[u], low[v]);
        }
        if (low[v] > dfn[u]) {
            if (u < v) p.push_back({u, v});
            else p.push_back({v, u});
        }
    }
    vis[u] = false;
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
        e[u].push_back(v);
        e[v].push_back(u);
    }
    tarjan(1);
    std::sort(p.begin(), p.end());
    for (auto i : p) {
        printf("%d %d\n", i.first, i.second);
    }
}