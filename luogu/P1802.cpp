#include <cstdio>
#include <algorithm>

const int maxn = 1e3 + 8;
int n, x;
int a[maxn], b[maxn], c[maxn], dp[maxn][maxn];

int main() {
    scanf("%d%d", &n, &x);
    // int minans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", a + i, b + i, c + i);
        // minans += a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = std::max(dp[i - 1][j] + a[i], j < c[i] ? 0 : (dp[i - 1][j - c[i]] + b[i]));
        }
    }
    printf("%lld", 5ll * dp[n][x]);
}