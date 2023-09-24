#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::min;

const int maxn = 1e4 + 8;
vector<int> e[maxn], dfn, low, in;
int cnt = 0;

int tarjan(int u, int n) {
    if (low[u]) {
        if (!in[u]) return n;
        return low[u];
    }
    in[u] = true;
    dfn[u] = low[u] = ++cnt;
    for (int v : e[u]) {
        low[u] = min(low[u], tarjan(v, n));
    }
    in[u] = false;
    return low[u];
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
    
}

int main() {
    P2341();
    return 0;
}
