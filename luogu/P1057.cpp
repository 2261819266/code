#include <cstdio>

const int maxn = 35;
int dp[maxn][maxn], n, m;

// int f(int x = 0, int y = m) {
//     if (n % 2 == 0 && m % 2 == 1) return 0;
//     x %= n;
//     if (y == 0) return !x;
//     if (dp[x][y]) return dp[x][y];
//     return dp[x][y] = f(x + 1, y - 1) + f(x + n - 1, y - 1);
// }

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d", &n, &m);
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = dp[i - 1][(j + 1) % n] + dp[i - 1][(j + n - 1) % n];
        }
    }
    printf("%d\n", dp[m][0]);
}