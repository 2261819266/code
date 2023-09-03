#include <cstdio>
#include <cstring>
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

const int maxn = 10005;
int  dis[maxn][maxn];

void init() { memset(dis, 0x7f, sizeof(dis)); }

void Floyed(int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j && j != k && i != k && (dis[i][j] > dis[i][k] + dis[k][j]))
                    dis[i][j] = dis[i][k] + dis[k][j];
}

int main() {
#ifdef LOCAL
    freopen("E:\\code\\in.in", "r", stdin);
    freopen("E:\\code\\out.out", "dis", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    int x;
    scanf("%d", &x);
    init();
    for (int c = 0; c < m; c++) {
        int u, v, w1;
        scanf("%d%d%d", &u, &v, &w1);
        dis[u][v] = min(w1, dis[u][v]);
    }
    for (int c = 1; c <= n; c++)
        dis[c][c] = 0;
    Floyed(n);
    for (int c = 1; c <= n; c++) {
        if (dis[x][c] > 0x70000000)
            printf("%d", 0x7fffffff);
        printf("%d ", dis[x][c]);
    }
}