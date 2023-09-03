#include <cstdio>
#include <vector>

using std::vector;

const int maxn = 1e5 + 8;
vector<int> e[maxn];

void addEdge(int u, int v) {
    e[u].push_back(v);
    e[v].push_back(u);
}

int f[maxn], c[maxn], d[maxn];

void build(int u = 1) {
    for (int v : e[u]) {
        if (v != f[u]) {
            f[v] = u;
            d[v] = d[u] + 1;
            build(v);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", c + i); 
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
    f[1] = d[1] = 1;
    build();
}
