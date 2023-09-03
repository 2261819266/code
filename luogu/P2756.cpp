#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int m, n, s, t;
int mp[310][310];
struct Edge {
    int to;
    int w;
    Edge *next;
    Edge(int _to = 0, int _w = 0, Edge *_next = 0)
        : to(_to), w(_w), next(_next) {}
    Edge operator++() {
        Edge *x = this->next;
        if (x)
            return *x;
        else
            return {-1, 0, nullptr};
    }
    Edge operator++(int) { return *this = ++*this; }
    int operator*() { return w; }
    operator bool() { return ~to; }
    bool operator<(const Edge &b) const { return w < b.w; }
};

struct EdgeTable {
    Edge **head;

    Edge begin(int x) {
        auto y = head[x];
        if (y)
            return *y;
        else
            return {-1, 0, nullptr};
    }
    EdgeTable(int maxn_ = 1e5 + 10) {
        head = new Edge *[maxn_];
        memset(head, 0, sizeof(int) * maxn_);
    }
    void add_edge(int u, int v, int w = 1) {
        Edge *e = new Edge(v, w, head[u]);
        head[u] = e;
    }
};

const int inf = 0x3f3f3f3f;
const int maxn = 200 + 10;
EdgeTable e(maxn * maxn);

Edge cur[maxn];
int dep[maxn], vis[maxn];
int maxflow = 0;
int vi;

bool bfs() {
    // memset(dep, 0x3f, sizeof(dep));
    // memset(vis, 0, sizeof(vis));
    for (int i = s; i <= t; ++i) {
        dep[i] = 0x3f3f3f3f;
        vis[i] = false;
        if (e.head[i])
            cur[i] = *e.head[i];
    }
    dep[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // vis[u] = 0;
        for (auto i = e.begin(u); i; i++) {
            if (dep[i.to] > dep[u] + 1 && mp[u][i.to]) {
                dep[i.to] = dep[u] + 1; //注意与EK的区别
                if (vis[i.to] == 0) {
                    q.push(i.to);
                    vis[i.to] = 1;
                }
            }
        }
    }
    // if (dep[t] != 0x3f3f3f3f3f3f3f3f)
    //     return 1;
    // return 0;
    return dep[t] < maxn;
} //给增广路上的点分层

int dfs(int u, int flow) {
    int rlow = 0;
    if (u == t) {
        vi = 1;
        maxflow += flow;
        return flow;
    }
    int used = 0;
    for (auto i = cur[u]; i; i++) {
        cur[u] = i;
        int v = i.to;
        if (mp[u][v] && dep[v] == dep[u] + 1) {
            rlow = dfs(v, min(flow, mp[u][v]));
            if (rlow) {
                used += rlow;
                mp[u][v] -= rlow;
                mp[v][u] += rlow;
                if (used == rlow) {
                    break;
                }
            }
        }
    }
    return used;
} //寻找增广路

int Dinic() {
    while (bfs()) {
        dfs(s, inf);
    }
    return maxflow;
} // Dinic寻找最大流
signed main() {
    #ifdef LOCAL
    LOCALfo
    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
    #endif
    scanf("%d %d", &m, &n);
    int u, v;
    s = 0, t = n + 1;
    for (int i = 1; i <= m; ++i) {
        e.add_edge(s, i);
        e.add_edge(i, s);
        mp[s][i] = 1;
    }
    for (int i = m + 1; i <= n; ++i) {
        e.add_edge(i, t);
        e.add_edge(t, i);
        mp[i][t] = 1;
    }
    while (true) {
        scanf("%d %d", &u, &v);
        if (!(u != -1 && v != -1)) break;
        e.add_edge(u, v);
        e.add_edge(v, u);
        mp[u][v] = 1;
    }
    printf("%d\n", Dinic());
    for (int i = 1; i <= m; i++) {
        for (auto j = e.begin(i); j; j++) {
            int v = j.to;
            if (!mp[i][v] && v > m) {
                printf("%d %d\n", i, v);
                break;
            } 
        }
    }
    return 0;
}