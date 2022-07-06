#include <cstdio>
#include <iostream>
#include <string.h>

const int maxn = 1001;
int d[maxn][maxn], a[maxn][maxn], b, c, e, n;

int solve(int i, int j) {
    if (d[i][j] >= 0)
        return d[i][j];
    return d[i][j] =
               a[i][j] +
               (i == n ? 0 : std::max(solve(i + 1, j), solve(i + 1, j + 1)));
}

int main() {
    memset(d, -1, sizeof(d));
    scanf("%d", &n);
    for (c = 1; c <= n; c++)
        for (e = 1; e <= c; e++)
            scanf("%d", &a[c][e]);

    printf("%d", solve(1, 1));
}