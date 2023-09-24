#include <iostream>
#include <vector>

using std::cin;
using std::vector;
using std::cout;

const int maxn = 1e4 + 8;

vector<int> e[maxn], k;

bool dfs(int u) {
    if (~k[u]) return k[u];
    k[u] = -2;
    int ans = 0;
    for (int v : e[u]) {
        if (k[v] >= 0) ans |= dfs(v);
    }
    return k[u] = ans;
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
    k.assign(n + 1, -1);
    k[t] = 1;
    for (int i = 1; i <= n; i++) {
        dfs(i);
        cout << k[i] << " ";
    }
}

int main() {
    P2296();
}