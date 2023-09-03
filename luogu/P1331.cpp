#include <cstdio>

const int maxn = 1010;
int a[maxn][maxn], n, m;

int dfs(int x, int y, int k, int q = 0) {
    if (a[x][y] <= 0 && a[x][y] != k)
        return 0;
    if ((a[x - 1][y] < 0 && a[x - 1][y] != k) ||
        (a[x + 1][y] < 0 && a[x + 1][y] != k) ||
        (a[x][y + 1] < 0 && a[x][y + 1] != k) ||
        (a[x][y - 1] < 0 && a[x][y - 1] != k))
        return -1;
    // if (a[x][y] < 0 && a[x][y] != k)
    //     return -1;
    int k1 = 0, k2 = 0, k3 = 0;
    if (q <= 0)
        k1 = dfs(x + 1, y, k, -1);
    if (q >= 0)
        k2 = dfs(x, y + 1, k, 1);
    if (q == 0)
        k3 = dfs(x + 1, y + 1, k);
    a[x][y] = k;
    if (k1 == -1 || k2 == -1 || (k1 == 1 && k2 == 1 && k3 == 0) ||
        (((k1 == 1) ^ (k2 == 1)) && k3 != 0))
        return -1;
    return 1;
}

int main() {
#ifdef LOCAL
    freopen("E:\\code\\in.in", "r", stdin);
    freopen("E:\\code\\out.out", "w", stdout);
#endif
    char s[maxn];
    scanf("%d%d", &n, &m);
    for (int c = 1; c <= n; c++) {
        scanf("%s", s);
        for (int d = 1; d <= m; d++)
            a[c][d] = (s[d - 1] == '.' ? 0 : 1);
    }
    int k = 0;
    for (int c = 1; c <= n; c++) {
        for (int d = 1; d <= m; d++) {
            int k1 = dfs(c, d, --k);
            if (k1 == -1) {
                printf("Bad placement.");
                return 0;
            }
            if (k1 == 0)
                k++;
        }
    }
    printf("There are %d ships.", -k);
}