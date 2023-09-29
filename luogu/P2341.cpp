#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::min;

const int maxn = 1e4 + 8;
vector<int> e[maxn], dfn, low, in, E[maxn], l2E, f;
int dfncnt = 0, colcnt;

int tarjan(int u, int n) {
    if (low[u]) {
        if (!in[u]) return n;
        return low[u];
    }
    in[u] = true;
    dfn[u] = low[u] = ++dfncnt;
    for (int v : e[u]) {
        low[u] = min(low[u], tarjan(v, n));
    }
    in[u] = false;
    return low[u];
}

int dfs(int u) {
    if (f[u]) return f[u];
    int ans = 1;
    for (int v : E[u]) {
        ans += dfs(v);
    }
    return f[u] = ans;
}

void P2341() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }
    low.assign(n + 1, 0);
    dfn.assign(n + 1, 0);
    in.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        tarjan(i, n);
        // cout << low[i] << " ";
    }
    vector<vector<int>> a;
    l2E.assign(n + 1, 0);
    f.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (low[i] == dfn[i]) 
            a.push_back(vector<int>()), l2E[i] = colcnt++;
    }
    for (int u = 1; u <= n; u++) {
        a[l2E[low[u]]].push_back(u);
        for (int v : e[u]) {
            if (low[u] != low[v]) E[l2E[low[v]]].push_back(l2E[low[u]]);
        }
    }
    for (int i = 0; i < a.size(); i++) {
        if (dfs(i) == a.size()) {
            cout << a[i].size();
            return;
        } 
    }
    cout << 0;
}

int main() {
    P2341();
    return 0;
}
