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

void add(int u = 1) {
    for (int v : e[u]) {
        if (f[v] == u) {
            if (c[v] == c[f[u]] && u > 1) addEdge(c[v], c[f[u]]);
            for (int w : e[u]) {
                if (f[w] == u && w != v && c[w] == c[v]) {
                    addEdge(v, w);
                }
            }
        }
    }
}

int cnt, in[maxn];
vector<vector<int>> a;

void dfs(int u) {
    if (in[u]) return;
    in[u] = true;
    a[cnt].push_back(u);
    for (int v : e[u]) {
        if (!in[v] && c[u] == c[v]) {
            dfs(v);
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
    add();

    for (int i = 1; i <= n; i++){
        dfs(i);
    }

}
