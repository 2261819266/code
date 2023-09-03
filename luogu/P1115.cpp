#include <cstdio>
#include <algorithm>
#define f(x, y, z) for (auto x = y, __ = z; x < __; ++x)

const int maxn = 2e5 + 8;
int a[maxn], dp[maxn];

int main() {
#ifdef LOCAL    
    LOCALfo
#endif
    int n, ans = -1e4;
    scanf("%d", &n);
    f(i, 1, n + 1) {
        scanf("%d", a + i);
        dp[i] = std::max(dp[i - 1] + a[i], a[i]);
        ans = std::max(ans, dp[i]);
    }
    printf("%d", ans);
    return 0;
}