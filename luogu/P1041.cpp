#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 1000;
int to[maxn * 10], next[maxn * 10], head[maxn], t = 0, now[maxn];

void addedge(int u, int v) {
    to[u] = v;
    next[u] = head[u];
    head[u] = t++;
}

int f(int x) {
    if (now[x]) return 0;
    int ans = maxn, j = 0;
    now[x] = 1;
    for (int i = head[x]; ~i; i = next[i], j++) {
        int ans_ = 0;
        now[i] = 1;
        for (int k = head[x]; ~k; k = next[k]) {
            if (k - i) ans_ += f(to[k]);
        }
        now[i] = 0;
        ans = std::min(ans, ans_);
    }
    now[x] = 0;
    return ans + j - 1;
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n, m;
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addedge(u, v);
        addedge(v, u);
    }
    printf("%d\n", f(1));
}