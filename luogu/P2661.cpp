#include <algorithm>
#include <cstdio>
#include <stack>

const int maxn = 2e5 + 8;
int a[maxn], dfn[maxn], low[maxn], col[maxn], cnt, size[maxn], num;
bool vis[maxn];
std::stack<int> s;

void dfs(int u) {
    vis[u] = true;
    dfn[u] = low[u] = ++cnt;
    s.push(u);
    if (!dfn[a[u]]) 
        dfs(a[u]),
        low[u] = std::min(low[u], low[a[u]]);
    if (vis[a[u]])
        low[u] = std::min(low[u], low[a[u]]);
    if (dfn[u] == low[u]) {
        num++;
        while (true) {
            int t = s.top();
            col[t] = num;
            size[num]++;
            vis[t] = false;
            s.pop();
            if (t == u) break;
        }
    }
}

void P2661() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        if (a[i] == i) {
            printf("%d", 1);
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            dfs(i);
        }
    }
    int ans = maxn;
    for (int i = 1; i <= n; i++) {
        if (size[i] > 1 && size[i] < ans) ans = size[i];
    }
    printf("%d", ans);
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    P2661();
    return 0;
}