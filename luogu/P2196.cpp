#include <cstdio>
#include <algorithm>

const int maxn = 21;
int a[maxn], to[maxn][maxn], n, dp[maxn];

int dfs(int x) {
    if (dp[x]) return dp[x];
    dp[x] = a[x];
    for (int i = 1; i + x <= n; i++) {
        if (to[x][i]) dp[x] = std::max(dfs(x + i) + a[x], dp[x]);
    }
    return dp[x];
}

void print(int ans, int x = 0) {
    ans -= a[x];
    for (int i = 1; i + x <= n; i++) {
        if (dp[i + x] == ans)
            return printf("%d ", i + x), print(ans, x + i);
    }
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = 1; i + j <= n; j++) {
            if (!i) to[i][j] = 1; else
            scanf("%d", &to[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = dfs(i);
        ans = std::max(ans, x);
    }
    print(ans);
    printf("\n%d", ans);
} 