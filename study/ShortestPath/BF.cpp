#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

const int maxn = 1e5 + 8, maxm = 2e5 + 8, inf = 0x3f3f3f3f;
struct E {
    int to, w;
} ;
std::vector<E> e[maxn];
int dis[maxn], vis[maxn], cnt[maxn];

bool BF(int n, int s) {
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    bool flag;
    for (int i = 1; i <= n; i++) {
        flag = false;
        for (int u = 1; u <= n; u++) {
            if (dis[u] == inf) continue;
            for (auto j : e[u]) {
                int v = j.to, w = j.w;
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    flag = true;
                }
            }
        }
        if (!flag) break;
    }
    return flag;
}

bool spfa(int n, int s) {
    std::queue<int> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    q.push(s) ;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (auto i : e[u]) {
            int v = i.to, w = i.w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] > n) return false;
                if (!vis[v]) vis[v] = true, q.push(v);
            }
        }
    }
    return true;
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back({v, w});
    }
    spfa(n, s);
    for (int i = 1; i <= n; i++) {
        if (dis[i] == inf) dis[i] = 0x7fffffff;
        printf("%d ", dis[i]);
    }
}