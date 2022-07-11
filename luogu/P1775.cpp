#include <cstdio>
#include <algorithm>
#define f(x, y, z) for (auto x = y, __ = z; x < __; ++x)

const int maxn = 305;
int n, a[maxn], dp[maxn][maxn], s[maxn];

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d", &n);
    f(i, 1, n + 1) scanf("%d", a + i), s[i] = s[i - 1] + a[i];
    f(i, 1, n) {
        f(l, 1, n - i + 1) {
            int r = i + l;
            dp[l][r] = 0x3fffffff;
            f(j, l, i + l) { 
                dp[l][r] = std::min(dp[l][r], s[r] - s[l - 1] + dp[l][j] + dp[j + 1][r]);
            }
        }
    }
    printf("%d", dp[1][n]);
}