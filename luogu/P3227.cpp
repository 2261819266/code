#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

const int maxm = 50;
const int maxn = maxm * maxm * maxm, inf = 0x3f3f3f3f;
struct E {
    int to, w, b;
};
int n, s, t, a[maxm][maxm][maxm], f[maxm][maxm][maxm];
std::vector<E> e[maxn];

void addEdge(int u, int v, int w) {
    int su = e[u].size();
    int sv = e[v].size();
    e[u].push_back({v, w, sv});
    e[v].push_back({u, 0, su});
}

int vis[maxn], dep[maxn], cur[maxn];

bool bfs() {
    for (int i = s; i <= t; i++) {
        vis[i] = false;
        dep[i] = inf;
        cur[i] = 0;
    }
    dep[s] = 0;
    std::queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto i : e[u]) {
            int v = i.to, w = i.w;
            if (dep[v] > dep[u] + 1 && w) {
                dep[v] = dep[u] + 1;
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return dep[t] < inf;
}

int dfs(int u = s, int x = inf) {
    int ans = 0;
    if (u == t) return x;
    for (int i = cur[u]; i < e[u].size(); i++) {
        cur[u] = i;
        int v = e[u][i].to, b = e[u][i].b, &w = e[u][i].w;
        if (dep[v] == dep[u] + 1 && w) {
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

int Dinic() {
    int ans = 0;
    while (bfs()) {
        while (true) {
            int x = dfs();
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
    int P, Q, R, D;
    scanf("%d%d%d%d", &P, &Q, &R, &D);
    int cnt = 0;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= P; j++) {
            for (int k = 1; k <= Q; k++) {
                scanf("%d", &a[i][j][k]);
                f[i][j][k] = ++cnt;
            }
        }
    }
    s = 0;
    t = ++cnt;
    const int way[4][2] = {1, 0, 0, 1, 0, -1, -1, 0};
    for (int i = 0; i <= R; i++) {
        for (int j = 1; j <= P; j++) {
            for (int k = 1; k <= Q; k++) {
                int u = f[i][j][k], v = f[i + 1][j][k], w = a[i][j][k];
                if (i == 0) {
                    addEdge(s, v, inf);
                } else if (i == R) {
                    addEdge(u, t, w);
                } else {
                    addEdge(u, v, w);
                }
                if (i > D) {
                    for (int o = 0; o < 4; o++) {
                        int l = f[i - D][j + way[o][0]][k + way[o][1]];
                        if (!l) continue;
                        addEdge(u, l, inf);
                    }
                }
            }
        }
    }
    // for (int i = 0; i <= t; i++) {
    //     for (auto x : e[i]) {
    //         if (x.w) printf("%d %d %d\n", i, x.to, x.w);
    //     }
    // }
    printf("%d", Dinic());
}