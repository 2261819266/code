#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>

const int maxn = 205;
std::vector<int> e[maxn];
int vis[maxn], dfn[maxn], low[maxn], col[maxn], cnt, num, size[maxn], in[maxn];
std::stack<int> s;

using std::min;

void tarjan(int u) {
    s.push(u);
    vis[u] = true;
    low[u] = dfn[u] = ++cnt;
    for (int v : e[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (vis[v]) {
            low[u] = min(low[u], low[v]);
        }
    }
    if (dfn[u] == low[u]) {
        num++;
        while (true) {
            int x = s.top();
            s.pop();
            col[x] = num;
            size[num]++;
            vis[x] = false;
            if (x == u) return;
        }
    }
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1 ;i <= n; i++) {
        int x;
        while (~scanf("%d", &x) && x) {
            e[i].push_back(x);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    for (int u = 1; u <= n; u++) {
        for (int v : e[u]) {
            if (col[u] != col[v]) {
                in[col[v]]++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= num; i++) {
        if (!in[i]) ans++;
    }
    printf("%d\n", ans);
}