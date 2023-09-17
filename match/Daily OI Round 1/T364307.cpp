#include <cstdio>
#include <vector>
#include <set>

using std::vector;
using std::set;

const int maxn = 1e0 + 8;
set<int> e[maxn];

void addEdge(int u, int v) {
    e[u].insert(v);
    e[v].insert(u);
}

int fa[maxn], c[maxn], d[maxn];

void build(int u = 1) {
    for (int v : e[u]) {
        if (v != fa[u]) {
            fa[v] = u;
            d[v] = d[u] + 1;
            build(v);
        }
    }
}

void add(int u = 1) {
    for (int v : e[u]) {
        if (fa[v] == u) {
            if (c[v] == c[fa[u]] && u > 1) addEdge(v, fa[u]);
            for (int w : e[u]) {
                if (fa[w] == u && w != v && c[w] == c[v]) {
                    addEdge(v, w);
                }
            }
            add(v);
        }
    }
}

int cnt = -1, in[maxn];
vector<vector<int>> a;
const vector<int> VECTOR_NULL;
const int M = 1e9 + 7;

void dfs(int u) {
    in[u] = true;
    a[cnt].push_back(u);
    for (int v : e[u]) {
        if (!in[v] && c[u] == c[v]) {
            dfs(v);
        }
    }
}

long long f[maxn], g[maxn];

long long find(int u) {
    g[u] = true;
    long long ans = 1;
    for (int v : e[u]) {
        if (c[v] == c[u] && g[v]) {
            ans += f[v];
            ans %= M;
        }
    }
    f[u] = ans;
    for (int v : e[u]) {
        if (c[v] == c[u] && !g[v]) {
            ans += find(v);
            ans %= M;
        }
    }
    return ans;
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

    fa[1] = d[1] = 1;
    build();
    add();

    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            a.push_back(VECTOR_NULL);
            cnt++;
            dfs(i);
        }
    }

    long long ans = 0;
    for (auto i : a) {
        ans += find(i[0]);
        ans %= M;
    }
    printf("%lld\n", ans % M);
}
