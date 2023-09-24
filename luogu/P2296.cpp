#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::vector;
using std::cout;
using std::queue;

const int maxn = 1e4 + 8;

vector<int> e[maxn], p, q;

bool dfs(int u) {
    if (~p[u]) return q[u];
    p[u] = -2;
    bool x = e[u].size(), y = 0;
    for (int v : e[u]) {
        if (q[v] > -2) y |= dfs(v), x &= dfs(v);
    }
    p[u] = x;
    return q[u] = y;
}

void P2296() {
    int n, m, s, t;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }
    cin >> s >> t;
    p.assign(n + 1, -1);
    q.assign(n + 1, -1);
    p[t] = q[t] = 1;
    for (int i = 1; i <= n; i++) {
        dfs(i);
        // cout << p[i] << " ";
    }
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        
    }
}

int main() {
    P2296();
}