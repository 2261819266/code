#include <algorithm>
#include <cstdio>
#include <string.h>

const int maxn = 155, maxm = 5005;
int head[maxn], top, hn[maxn];

struct E {
    int to, next;
    /* data */
} edge[maxm * 4];

void init(int n) { memset(head, -1, sizeof(head)); }

void addedge(int u, int v) {
    edge[top] = (E){v, head[u]}, head[u] = top++;
    edge[top] = (E){u, head[v]}, head[v] = top++;
    hn[u]++, hn[v]++;
}

int n, m, u, v, c, d, e, k[maxn];

int main() {
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif

    scanf("%d%d", &n, &m);
    init(n);
    for (c = 0; c < m; c++)
        scanf("%d%d", &u, &v), addedge(u, v);
    for (c = 1; c <= n; c++) {
        if (hn[c] == 1) {
            for (d = head[c], e = 0; d != -1; d = edge[d].next)
                k[e++] = edge[d].to, hn[k[e - 1]]++;
            std::sort(k, k + e);
            for (d = 0; d < e; d++)
                printf("%d %d\n", c, k[d]);
        }
    }
}