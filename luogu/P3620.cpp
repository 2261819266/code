#include <cstdio>
#include <algorithm>
#define f(x, y, z) for (int x = y, __ = z; x < __; ++x)

const int maxn = 1e5 + 8;
int a[maxn], b[maxn], dp[maxn];

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    f(i, 1, n + 1) {
        scanf("%d", a + i);
        b[i] = a[i] - a[i - 1];
    }
    dp[1] = b[1];
    dp[2] = std::max(b[1], b[2]);
    f(i, 3, n + 1) {
        dp[i] = std::max(dp[i] + )
    }
}