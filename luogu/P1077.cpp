#include <cstdio>

const int maxn = 105, M = 1e6 + 7;
int dp[maxn][maxn];

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= x && k <= j; k++) {
                dp[i][j] += dp[i - 1][j - k];
                dp[i][j] %= M;
            }
        }
    }
    printf("%d\n", dp[n][m]);
}
