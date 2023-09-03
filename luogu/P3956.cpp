#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;

const int maxn = 1e2 + 8, inf = maxn * maxn * maxn;
unsigned int a[maxn][maxn], dp[maxn][maxn][3], vis[maxn][maxn];
int m, n;

const int w[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

void updata(unsigned &x, int y) {
    x = min(int(x), y);
}

int dfs(int x, int y, int k = 0) {
    if (~dp[x][y][k]) return dp[x][y][k];
    if (!x || !y || x > m || y > m) return dp[x][y][k] = inf;
    dp[x][y][k] = inf;
    if (a[x][y]) {
        for (int i = 0; i < 4; i++) {
            int xx = x + w[i][0], yy = y + w[i][1];
            updata(dp[x][y][k], dfs(xx, yy, (!a[xx][yy]) * a[x][y]) + 2 * (!a[xx][yy]) + (a[x][y] != a[xx][yy] && a[xx][yy]));
        }
    } else {
        for (int i = 0; i < 4; i++) {
            int xx = x + w[i][0], yy = y + w[i][1];
            if (!a[xx][yy]) continue;
            updata(dp[x][y][k], dfs(xx, yy) + (k != a[xx][yy]));
        }
    }
    return dp[x][y][k];
}

void P3956() {
    scanf("%d%d", &m, &n);
    memset(dp, -1, sizeof(dp));
    dp[m][m][0] = dp[m][m][1] = dp[m][m][2] = 0;
    for (int i = 0; i < n; i++) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        a[x][y] = c + 1;
    }
    int ans = dfs(1, 1);
    if (ans == inf) ans = -1;
    // for (int i = 1; i <= m; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         printf("%d\t", a[i][j]);
    //     }
    //     putchar('\n');
    // }
    //     putchar('\n');
    // for (int i = 1; i <= m; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         int x = min(dp[i][j][0], min(dp[i][j][1], dp[i][j][2]));
    //         if (x == inf) x = -1;
    //         printf("%d\t", x);
    //     }
    //     putchar('\n');
    // }
    printf("%d", ans);
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    P3956();
    return 0;
}
