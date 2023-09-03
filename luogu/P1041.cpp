#include <cstdio>
#include <vector>

const int maxn = 305;

std::vector<int> e[maxn], s[maxn], d;

void addEdge(int u, int v) {
    e[u].push_back(v);
    e[v].push_back(u);
}

void build(int u = 1) { 
    for (int v : e[u]) {
        if (!d[v] && v > 1) {
            d[v] = d[u] + 1;
            s[u].push_back(v);
            build(v);
        }
    }
}

int dfs(int u = 1) {
    int mx = 0, sum = 0;
    for (int v : s[u]) {
        int x = dfs(v);
        sum += x;
        mx = std::max(mx, x);
    }
    return sum - mx + 1;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    d.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
    build();
    // printf("%d\n", dfs(1));
    for (int i : d) {
        printf("%d\n", d[i]);
    }
}
