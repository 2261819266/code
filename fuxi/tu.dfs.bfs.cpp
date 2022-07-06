#include <cstdio>
#include <cstring>
#include <queue>

const int maxn = 10005, maxm = 10005;

struct E {
    int to, w, next;
    E() { next = -1; }
    /* data */
} edge[maxm];
int head[maxn], p[maxn], q[maxn], top;

void init() { memset(head, -1, sizeof(head)); }

void dfs(int k) {
    if (p[k])
        return;

    p[k] = true;
    printf("%d ", k);
    for (int c = head[k]; c != -1; c = edge[c].next) {
        if (!p[edge[c].to])
            dfs(edge[c].to);
    }
}

void bfs(int k) {
    std::queue<int> a;
    a.push(k);
    q[k] = true;
    while (!a.empty()) {
        int k = a.front();
        printf("%d ", k);
        for (int c = head[k]; c != -1; c = edge[c].next)
            if (!q[edge[c].to])
                a.push(edge[c].to), q[edge[c].to] = true;
        a.pop();
    }
}

void addedge(int u, int v, int w = 0) {
    edge[top].to = v;
    edge[top].w = w;
    edge[top].next = head[u];
    head[u] = top++;
    edge[top].to = u;
    edge[top].w = w;
    edge[top].next = head[v];
    head[v] = top++;
}

int main() {
#ifdef LOCAL
    freopen("E:\\code\\in.in", "r", stdin);
    freopen("E:\\code\\out.out", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    init();
    for (int c = 1; c <= m; c++) {
        int u, v, w;
        scanf("%d%d", &u, &v);
        addedge(u, v);
    }
    dfs(1);
    printf("\n");
    bfs(1);
}