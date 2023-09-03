#include <cstdio>
#include <algorithm>
#define f(x, y, z) for (auto x = y, __ = z; x < __; ++x)

const int maxn = 1e3 + 8;
int a[maxn], b[maxn], c[maxn], dp[maxn];

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n, m, x;
    scanf("%d%d%d", &n, &m, &x);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", a + i, b + i, c + i);
        if (b[i] > m) i--, n--;
    }
    f(i, 1, n + 1) {
        for (int j = x; j >= c[i]; --j) {
            dp[j] = std::max(dp[j], dp[j - c[i]] + a[i]);
        }
    }
    printf("%d", dp[x]);
}