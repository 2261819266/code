#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

const int maxm = 205, maxn = maxm * maxm;
struct E {
    int to, w, back;
};
std::vector<E> e[maxn];
int n, m, f[maxm][maxm];
bool is[maxn], col[maxn];
int s = 0, t;


void dfs(int x, int y, int) {
    int way[8][2] = {2, 1, 2, -1, 1, 2, 1, -2, -1, 2, -1, -2, -2, 1, -2, -1};
    int u = f[x][y];
    for (int i = 0; i < 8; i++) {
        int xx = x + way[i][0], yy = y + way[i][1];
        int v = f[xx][yy];
        if (v && col[v]) {
            if (col[u]) std::swap(u, v);
            int su = e[u].size(), sv = e[v].size();
            e[u].push_back({v, 1, sv});
            e[v].push_back({u, 0, su});
        }
    }
}

bool vis[maxn];
int dep[maxn], cur[maxn];
const int inf = 0x3f3f3f3f;

bool bfs() {
    for (int i = s; i <= t; i++) {
        vis[i] = false;
        dep[i] = inf;
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
            int v = i.to;
            if (dep[v] > dep[u] + 1 && i.w) {
                dep[v] = dep[u] + 1;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    return dep[t] < inf;
}

int dfs(int u, int x) {
    int ans = 0;
    if (u == t) return x;
    // for (auto &i : e[u]) {
    //     int v = i.to, b = i.back;
    //     if (dep[v] == dep[u] + 1 && i.w) {
    //         ans = dfs(v, std::min(x, i.w));
    //         if (ans) {
    //             i.w -= ans;
    //             e[v][b].w += ans;
    //             return ans;
    //         }
    //     }
    // }
    for (int i = cur[u]; i < e[u].size(); i++) {
        cur[u] = i;
        int v = e[u][i].to, b = e[u][i].back;
        int &w = e[u][i].w, &ww = e[v][b].w;
        if (dep[v] == dep[u] + 1 && w) {
            ans = dfs(v, std::min(x, w));
            if (ans) {
                w -= ans;
                ww += ans;
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
            int x = dfs(s, inf);
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
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = ++cnt;
            col[f[i][j]] = (i + j) % 2;
        }
    }
    t = cnt + 1;
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        is[f[x][y]] = true;
    }
    for (int i = 1; i <= cnt; i++) {
        if (is[i]) continue;
        int si = e[i].size();
        if (col[i]) {
            int st = e[t].size();
            e[i].push_back({t, 1, st});
            e[t].push_back({i, 0, si});
        } else {
            int ss = e[s].size();
            e[s].push_back({i, 1, si});
            e[i].push_back({s, 0, ss});
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (is[f[i][j]]) continue;
            dfs(i, j, 0);
        }
    }
    // for (int i = s; i <= t; i++) {
    //     if (!is[i]) {
    //         for (auto j : e[i]) {
    //             if (j.w)
    //                 printf("%d %d\n", i, j.to);
    //         }
    //     }
    // }
    printf("%d\n", n * n - m - Dinic());
}