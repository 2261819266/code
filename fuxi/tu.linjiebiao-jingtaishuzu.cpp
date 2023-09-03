#include <cstdio>
#include <string.h>

const int maxn = 10005;
const int maxm = 10005;
int head[maxn];
int cnt = 0;

struct node {
    int u;    //起点
    int v;    //终点
    int w;    //权值
    int next; //指向上一条边
} edge[maxm * 4];

void add(int u, int v, int w) {
    edge[cnt].u = u;
    edge[cnt].v = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void init() { memset(head, -1, sizeof(head)); }

int main() {

#ifndef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        init();
        for (int c = 1; c <= m; c++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
        int u;
        scanf("%d", &u);

        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            int w = edge[i].w;
            printf("%d %d\n", v, w);
        }
    }
}