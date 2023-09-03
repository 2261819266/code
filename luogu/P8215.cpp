#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#define ll long long

const int maxn =  1e5 + 8;
const ll inf = 1e16;
struct E {
    int to;
    ll w;
    int back;
};
std::vector<E> e[maxn];
int n, m, s, t;

void addEdge(int u, int v, ll w) {
    int su = e[u].size();
    int sv = e[v].size();
    e[u].push_back({v, w, sv});
    e[v].push_back({u, 0, su});
}

int vis[maxn], dep[maxn], cur[maxn];

bool bfs() {
    for (int i = s; i <= t; i++) {
        vis[i] = false;
        dep[i] = 1e8;
        cur[i] = 0;
    }
    std::queue<int> q;
    q.push(s);
    dep[s] = 0;
    vis[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto i : e[u]) {
            int v = i.to, w = i.w;
            if (w && dep[v] > dep[u] + 1) {
                dep[v] = dep[u] + 1;
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return dep[t] < 1e8;
}

ll dfs(int u, ll x) {
    int ans;
    if (u == t) return x;
    for (int i = cur[u]; i < e[u].size(); i++) {
        cur[u] = i;
        int v = e[u][i].to, b = e[u][i].back;
        ll &w = e[u][i].w;
        if (w && dep[v] == dep[u] + 1) {
            ans = dfs(v, std::min(x, w));
            if (ans) {
                w -= ans;
                e[v][b].w += ans;
                return ans;
            }
        }
    }
    return 0;
}

ll Dinic() {
    ll ans = 0;
    while (bfs()) {
        while (true) {
            ll x = dfs(s, inf);
            if (!x) break;
            ans += x;
        }
    }
    return ans;
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d", &n, &m);
    s = 0;
    int n2 = n * 2;
    int n4 = n2 * 2;
    t = n4 + n + 1;
    for (int i = 0; i < n; i++) {
        int c[3], d[3], e[3];
        for (int j = 1; j <= 2; j++) {
            int v = i * 2 + j;
            addEdge(s, v, inf);
            scanf("%d%d%d", c + j, d + j, e + j);
            addEdge(v, n2 + v, c[j]);
            addEdge(n2 + v, t, d[j]);
        }
        int u = i * 2 + 1, v = u + 1;
        addEdge(n2 + u, n2 + v, e[2]);
        addEdge(n2 + v, n2 + u, e[1]);
        addEdge(n2 + u, n4 + i + 1, inf); //
        addEdge(n2 + v, n4 + i + 1, inf); //
        // addEdge(n4 + i + 1, t, 1); //
    }
    for (int i = 0; i < m; i++) {
        int A, B, a, b;
        scanf("%d%d%d%d", &A, &B, &a, &b);
        addEdge(n2 + A, n4 + (B + 1) / 2, b);
        addEdge(n4 + (A + 1) / 2, n2 + B, a);
    }
    // for (int i = 0; i <= t; i++) {
    //     for (auto j : e[i]) {
    //         if (j.w) printf("%d %d %d\n", i, j.to, j.w);
    //     }
    // }
    printf("%lld", Dinic());
}