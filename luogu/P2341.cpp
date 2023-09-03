#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>

const int maxn = 5e4 + 8;
std::vector<int> e[maxn];
int vis[maxn], dfn[maxn], low[maxn], cnt, a[maxn], col[maxn], num, size[maxn];
std::stack<int> s;

void dfs(int u) {
    vis[u] = true;
    dfn[u] = low[u] = ++cnt;
    s.push(u);
    for (int v : e[u]) {
        if (!dfn[v]) {
            dfs(v);
            low[u] = std::min(low[u], low[v]);
        } else if (vis[v]) {
            low[u] = std::min(low[u], low[v]);
        }
    }
    if (dfn[u] == low[u]) {
        num++;
        while (s.top() != u) {
            col[s.top()] = num;
            size[num]++;
            vis[s.top()] = false;
            s.pop();
        }
        col[s.top()] = num;
        size[num]++;
        vis[s.top()] = false;
        s.pop();
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
        e[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) dfs(i);
        // printf("%d ", col[i]);
    }
    for (int u = 1; u <= n; u++) {
        for (int v : e[u]) {
            if (col[u] != col[v]) {
                a[col[u]]++;
            }
        }
    }
    int x = 0;
    for (int i = 1; i <= n; i++) {
        if (!a[col[i]]) {
            if (!x) x = col[i];
            else if (x != col[i]) {
                puts("0");
                return 0;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (col[i] == x) ans++;
    }
    printf("%d", ans);
}
