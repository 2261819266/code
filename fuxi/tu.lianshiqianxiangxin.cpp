#include <cstdio>
#include <string.h>

const int maxn = 10005;
const int maxm = 10005;
int head[maxn], top;
struct E {
    int to, w, next;
    /* data */
} edge[maxm * 2];

void init(int n) { memset(head, -1, sizeof(head)), top = 0; }

void addedge(int u, int v, int w) {
    edge[top] = (E){v, w, head[u]}, head[u] = top++;
    edge[top] = (E){u, w, head[v]}, head[v] = top++;
}

int main() {
#ifndef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int n, m, c, d, e, u, v, w;

    scanf("%d%d", &n, &m);
    init(n);
    for (c = 0; c < m; c++)
        scanf("%d%d%d", &u, &v, &w), addedge(u, v, w);

    scanf("%d", &u);
    for (c = head[u]; c != -1; c = edge[c].next)
        printf("%d %d\n", edge[c].to, edge[c].w);
}