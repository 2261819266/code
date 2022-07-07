#include <cstdio>
#define ll __int128_t

const int maxn = 5e5 + 8, M = 1e9 + 7;
ll a[2][maxn];
ll b[2][maxn];
ll c[2][maxn];

ll get(int k, int l, int r) {
    return (b[k][r] - b[k][l - 1]);
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n;
    ll ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            b[i][j] = (b[i][j - 1] + a[i][j]) % M;
            c[i][j] = (c[i][j - 1] + b[i][j]) % M;
        }
    }
    for (int i = 1; i <= n; i++) {
        ans += b[0][i] * b[1][i];
        // ans %= M;
    }
    ans *= n;
    for (int i = 1; i <= n; i++) {
        ans -= b[0][i] * (c[1][n] - b[1][i]);
    }
    printf("%lld", (long long)(ans % M));
}