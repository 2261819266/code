#include <cstdio>

int a[10][10], n, m, t; // 0不能走  -1可以走  1走过了  2起点  3终点

void dfs(int x, int y, int k = 0) {
    int c, d, e;

    if (!a[x][y] || (a[x][y] == 2 && k == 0)||a[x][y]==1)
        return;

    if (a[x][y] == 3) {
        t++;
        return;
    }

    a[x][y] = 1;

    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
    a[x][y] = -1;
}

int x1, y11, k, x2, y2, c, d, e, u, v;

int main() {
    freopen("walk.in","r",stdin);
    freopen("walk.out","w",stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (c = 1; c <= n; c++)
        for (d = 1; d <= m; d++)
            a[c][d] = -1;

    scanf("%d%d%d%d", &x1, &y11, &x2, &y2);
    a[x1][y11] = 2;
    a[x2][y2] = 3;

    for (c = 0; c < k; c++)
        scanf("%d%d", &u, &v), a[u][v] = 0;

    dfs(x1, y11, 1);

    printf("%d", t);
}