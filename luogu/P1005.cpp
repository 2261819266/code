#include <cstdio>
#include <algorithm>
#define ll __int128_t

const int maxn = 101;
int a[maxn][maxn], n, m;
ll dp[maxn][maxn];

template<typename t> 
void print(t x) {
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

ll solve(int *a) {
    for (int i = 0; i < m; i++) {
        dp[i][0] = a[i];
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; i + j <= m; j++) {
            dp[j][i] = std::max(dp[j][i - 1] * 2 + a[i + j], dp[j + 1][i - 1] * 2 + a[j]);
        }
    }
    return dp[0][m - 1];
}

int main() {
#ifdef LOCAL
	LOCALfo
#endif
    scanf("%d%d", &n, &m);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
        ans += solve(a[i]);
    }
    print(ans * 2);
}