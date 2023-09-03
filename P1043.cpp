#include <cstdio>
#include <algorithm>
#include <cstring>

const int maxn = 108;
int dp[maxn][maxn][maxn], a[maxn], n, n2, m, sum[maxn];

int mod(int x) {
    return (x % 10 + 10) % 10;
}

int getsum(int l, int r) {
    return sum[r] - sum[l - 1];
}

int solve(bool (*cmp)(int, int)) { // < : min, > : max
    int ans = 0;
    memset(dp, cmp(0, 1) ? 0x3f : 0, sizeof(dp));
    for (int l = 1; l <= n2; l++) {
        for (int r = l; r <= n2; r++) {
            dp[l][r][1] = mod(getsum(l, r));
        }
    }
    for (int i = 1; i < n; i++) {
        for (int l = 1, r = l + i; r <= n2; l++, r++) {
            for (int j = 2; j <= m; j++) {
                for (int k = l; r - k >= j - 1; k++) {
                    int x = dp[l][k][1] * dp[k + 1][r][j - 1];
                    if (cmp(x, dp[l][r][j]))
                        dp[l][r][j] = x;

                }
            }
        }
    }
    ans = cmp(0, 1) ? 0x3fffffff : 0;
    for (int i = 1; i <= n; i++) {
        if (cmp(dp[i][i + n - 1][m], ans))
            ans = dp[i][i + n - 1][m];
    }
    return ans;
}

void P1043() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        a[i + n] = a[i];
    }
    n2 = n * 2;
    for (int i = 1; i <= n2; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    int min = solve([](int x, int y) { return x < y; });
    int max = solve([](int x, int y) { return x > y; });
    printf("%d\n%d\n", min, max);
}   

int main() {
    P1043();
    return 0;
}