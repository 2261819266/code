#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstring>
#define fo(x)                      \
    freopen(#x ".in", "r", stdin); \
    freopen(#x ".out", "w", stdout);

int gcd[205][205];

void init() {
    for (int i = 1; i <= 200; i++) {
        for (int j = 1; j <= 200; j++) {
            gcd[i][j] = std::__gcd(i, j) == 1;
        }
    }
}

const int maxn = 6e3 + 8, inf = 0x3f3f3f3f;
struct Node {
    int a, b, c;
    bool operator==(const Node &x) const { return gcd[a][x.a] + gcd[b][x.b] + gcd[c][x.c] <= 1; }
} a[maxn];

struct E {
    int to, next;
} edge[maxn << 10];
int head[maxn], cnt;

int w[maxn][maxn], pre[maxn];
int s = 0, t;

void addEdge(int u, int v, int _w) {
    if (!cnt)
        memset(head, -1, sizeof(head));
    edge[cnt] = { v, head[u] };
    head[u] = cnt++;
    w[u][v] = _w;
}

bool bfs() {
    memset(pre, -1, sizeof(pre));
    std::queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            if (w[u][v] && !~pre[v]) {
                pre[v] = u;
                if (v == t)
                    return true;
                q.push(v);
            }
        }
    }
    return false;
}

int EK() {
    int ans = 0;
    while (bfs()) {
        int min = inf;
        for (int i = t; i != s; i = pre[i]) {
            min = std::min(min, w[pre[i]][i]);
        }
        for (int i = t; i != s; i = pre[i]) {
            int u = pre[i];
            int v = i;
            w[u][v] -= min;
            w[v][u] += min;
        }
        ans += min;
    }
    return ans;
}

int main() {
    fo(match) int n, m;
    scanf("%d%d", &n, &m);
    init();
    t = n + m + 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
        addEdge(s, i, 1);
        addEdge(i, s, 0);
    }
    for (int i = n + 1; i <= m + n; i++) {
        scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
        addEdge(t, i, 0);
        addEdge(i, t, 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = n + 1; j <= m + n; j++) {
            if (a[i] == a[j])
                addEdge(i, j, 1), addEdge(j, i, 0);
        }
    }
    printf("%d", EK());
}