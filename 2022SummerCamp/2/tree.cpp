#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 2e3 + 10;
int read()
{
    int x, f = 1;
    char c;
    while ((c = getchar()) < 48 || c > 57)
        if (c == '-')
            f = -1;
    x = c ^ 48;
    while ((c = getchar()) > 47 && c < 58)
        x = (x << 3) + (x << 1) + (c ^ 48);
    return f * x;
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
int n, q;
int f[maxn];
int find(int x)
{
    while (x != f[x]) {
        x = f[x];
    }
    return x;
}

struct E {
    int to, next;
} edge[maxn << 2];
int h[maxn], cnt;

void addEdge(int u, int v) {
    edge[cnt] = {v, h[u]};
    h[u] = cnt++;
}

void dfs(int x) {
    for (int i = h[x]; ~i; i = edge[i].next) {
        int to = edge[i].to;
        if (to != 1 && !f[to]) dfs(to);
    }
}

signed main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    n = read(), q = read();
    memset(h, -1, sizeof(h));
    // for (int i = 1; i <= n; ++i) {
    //     f[i] = 1;
    // }
    for (int i = 1; i < n; ++i) {
        int u, v;
        u = read(), v = read();
        // if (u > v) {
        //     swap(u, v);
        // }
        addEdge(u, v);
        // f[v] = u;
    }
    dfs(1);
    for (int i = 1; i <= q; ++i) {
        int o = read(), x = read();
        if (o == 0) {
            f[x] = x;
        } else {
            print(find(x)), putchar('\n');
            // printf("%d\n", find(x));
        }
    }
    return 0;
}