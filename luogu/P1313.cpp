#include <cstdio>
#define f(x, y, z) for (auto x = y, __ = z; x < __; ++x)

const int maxn = 1e3 + 8, M = 1e4 + 7;
int a[maxn][maxn];

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int x, y, k, n, m;
    scanf("%d%d%d%d%d", &x, &y, &k, &n, &m);
    a[0][0] = 1, x %= M, y %= M;
    f(i, 1, k + 1) {
        a[i][0] = 1;
        f (j, 1, i + 1) {
            a[i][j] += a[i - 1][j] + a[i - 1][j - 1];
            a[i][j] %= M;
        }
    }
    int ans = 1;
    f(i, 0, n) ans *= x, ans %= M;
    f(i, 0, m) ans *= y, ans %= M;
    ans *= a[k][n];    
    printf("%d", ans % M);
}