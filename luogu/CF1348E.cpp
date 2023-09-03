#include <cstdio>
#include <algorithm>
#define int long long
const int maxn = 1e3;
int a[maxn][2], sum[2];
bool dp[maxn][maxn];

signed main() {
#ifdef LOCAL    
    LOCALfo
#endif
    int n, k;
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &a[i][0], &a[i][1]);
        sum[0] += a[i][0];
        sum[1] += a[i][1];
    }
    int l = sum[0] / k + sum[1] / k;
    int r = (sum[0] + sum[1]) / k;
    if (l == r) { 
        printf("%lld", r);
        return 0;
    }
    int ans = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; ++j) {
            // l = a[i] % k;
            dp[i][j] = std::max(dp[i][j], dp[i - 1][(j + k - a[i][0] % k) % k]);
            for (int l = 0; l <= std::min(k - 1, a[i][0]); ++l) {
                if ((a[i][0] - l) % k + a[i][1] >= k) {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][(j + k - l) % k]);
                }
            }
        }
    }
    for (int i = 0; i <= k - 1; ++i) {
        if (dp[n][i] && sum[0] + sum[1] - i >= k) {
            printf("%lld", (sum[0] + sum[1] - i) / k);
            return 0;
        }
    }
    printf("%lld", l);
    return 0;
}