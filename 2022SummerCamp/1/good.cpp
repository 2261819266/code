#include <cstdio>
#ifndef LOCAL
#define fo(x) freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout);
#endif
#define f(x, y, z) for (auto x = y, __ = z; x < __; ++x)

const int maxn = 205, M = 998244353;
int a[maxn][maxn], dp[maxn][maxn];

int main() {
    fo(good)
    int n;
    scanf("%d", &n);
    f(i, 1, n + 1) {
        int x;
        scanf("%d", &x);
        a[i][x] = 1;
    }
    f(i, 0, n + 2) {
        dp[0][i] = 1;
    }
    f(i, 1, n + 2) {
        dp[i][0] = 1;
        f(j, 1, n + 2) {
            if (!a[i][j]){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                dp[i][j] %= M; 
            }
        }
    }
    printf("%d", dp[n + 1][n + 1]);
}