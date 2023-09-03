#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

const int maxn = 2e5 + 8;

#define ll long long
#define fo(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);


struct E {
    int v;
    ll w;
};

struct Node {
    int i;
    ll dis;
    bool operator<(const Node &b) const {
        return dis > b.dis;
    }
};

using std::vector;
vector<E> e[maxn];
vector<ll> dis;

void dijkstra(int s) {
    dis.assign(maxn, 0xffffffffffff);
    std::priority_queue<Node> q;
    dis[s] = 0;
    q.push({s, 0});
    vector<bool> vis(maxn, false);
    while (!q.empty()) {
        int u = q.top().i;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto i : e[u]) {
            int v = i.v;
            int w = i.w;
            dis[v] = std::min(dis[v], dis[u] + w);
            q.push({v, dis[v]});
        }
    }
}

void train() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dijkstra(1);
    vector<bool> vis(maxn, false);
    int ans = 0;
    for (int i = 0; i < k; i++) {
        int x, w;
        scanf("%d%d", &x, &w);
        if (w < dis[x] && !vis[x]) vis[x] = true;
        else ans++;
    }
    printf("%d", ans);
}

int main() {
    fo(train);
    train();
    return 0;
}
