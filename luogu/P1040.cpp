#include <algorithm>
#include <cstdio>
#include <cstring>
#define ll long long

const int maxn = 100;
int n, a[maxn];
ll dp[maxn][maxn];

ll get(int l, int r, int k) {
    return dp[l][k - 1] * dp[k + 1][r] + dp[k][k];
}

void dfs(int l, int r) {
    if (l > r) return;
    if (l == r) {
        printf("%d ", l);
        return;
    }
    for (int k = l; k <= r; k++) {
        if (get(l, r, k) == dp[l][r]) {
            printf("%d ", k);
            dfs(l, k - 1);
            dfs(k + 1, r);
            return;
        }
    }
}

void P1040() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 1;
        }
        dp[i][i] = a[i];
    }
    for (int i = 1; i < n; i++) {
        for (int l = 1, r = i + l; r <= n; l++, r++) {
            for (int k = l; k <= r; k++) {
                dp[l][r] = std::max(dp[l][r], get(l, r, k));
            }
        }
    }
    printf("%lld\n", dp[1][n]);
    dfs(1, n);
}

int main() {
    P1040();
    return 0;
}