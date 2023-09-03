#pragma GCC optimize(3,"Ofast","inline")
#include <cstdio>
#include <cstring>
#define fo(x)                      \
    freopen(#x ".in", "r", stdin); \
    freopen(#x ".out", "w", stdout);
#define f(x, y, z) for (int x = y, __ = z; x < __; ++x)

inline void read(int &x) {
    int f = 1, c = getchar();
    x = 0;
    while (c < '0' || c > '9') {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    x *= f;
}

int ouf[40], OUF;

void print(int x)
{
    int y;
    if (x < 0)
        putchar('-'), x = -x;
    do
        y = x / 10, ouf[++OUF] = x - y * 10;
    while (x = y);
    for (; OUF; OUF--)
        putchar(ouf[OUF] ^ 48);
}

const int maxn = 2e6 + 8;
struct E {
    int to, next;
} edge[maxn << 2];
int head[maxn], cnt, fa[maxn], a[maxn];

inline void addEdge(int u, int v) {
    if (!cnt)
        memset(head, -1, sizeof(head));
    edge[cnt] = { v, head[u] };
    head[u] = cnt++;
}

inline void dfs(int x = 1) {
    for (int i = head[x]; ~i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == 1 || fa[to])
            continue;
        fa[to] = x;
        dfs(to);
    }
}

int main() {
    fo(tree) int n, m;
    read(n), read(m);
    int u, v;
    f(i, 1, n) {
        read(u), read(v);
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs();
    a[1] = 1;int op, x;
    f(i, 0, m) {
        read(op), read(x);
        if (op == 0)
            a[x]++;
        else {
            for (int j = x; j; j = fa[j]) {
                if (a[j]) {
                    print(j), putchar('\n');
                    break;
                }
            }
        }
    }
}