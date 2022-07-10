#include <cstdio>
#define f(x, y, z)  for (auto x = y, __ = z; x < z; ++x)

int a[7], dp[10005];
const int m[7] = {0, 1, 2, 3, 5, 10, 20};

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    f(i, 1, 7) {
        scanf("%d", a + i);
        f(j, 0, a[i]) {
            for (int k = 1001; k > 0; k--) {
                dp[k + m[i]] |= dp[k];
            }
            dp[m[i]] |= 1;
        }
    }
    int ans = 0;
    f(i, 1, 1001) {
        ans += dp[i] > 0;
    }
    printf("Total=%d", ans);
}