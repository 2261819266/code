#include <cstdio>
#include <vector>
#include <algorithm>



#define fo(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);

using std::vector;

const int maxn = 1e5 + 8;
int n, m, q;
struct E { int v, i; };
vector<E> e[maxn];
vector<bool> vis;
int ans;

void dfs(int u, int max) {
    if (vis[u]) return;
    vis[u] = true;
    ans++;
    for (auto i : e[u]) {
        if (i.i > max) continue;
        dfs(i.v, max);
    }
}

void explore() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back({v, i});
        e[v].push_back({u, i});
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        int l = 1, r = m;
        while (l < r) {
            int mid = (l + r) / 2;
            vis.assign(n, false);
            ans = 0;
            dfs(x, mid);
            dfs(y, mid);
            if (ans < z) l = mid + 1;
            else r = mid;
        }
        printf("%d\n", l);
    }
}

int main() {
    fo(explore)
    explore();
    return 0;
}