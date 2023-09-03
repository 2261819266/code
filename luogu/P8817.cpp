#include <algorithm>
#include <cstdio>
#include <vector>

using std::vector;

vector<vector<int>> e;
vector<int> w;
int k;

const int inf = 0x7fffffff;

void update(int &x, int y) {
    x = std::max(x, y);
}

int dfs(int u, int t = k, int n = 4) {
    if (u == 1 && !n) return 0;
    if (u != 1 && !n && !t) return -inf;
    int ans = 0;
    for (auto i : e[u]) {
        if (t)
            update(ans, dfs(i, t - 1, n));
        if (n)
            update(ans, dfs(i, k, n - 1));
    }
    return -inf;
}   

void P8817() {
    int n, m;
    scanf("%d%d%d", &n, &m, &k);
    e.assign(n + 1, {});
    w.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }

    
}
