#include <cstdio>
#define ll long long

const int maxn = 5e5 + 8, M = 1e9 + 7;
ll a[2][maxn];
ll b[2][maxn];

ll get(int k, int l, int r) {
    return (b[k][r] - b[k][l - 1]) % M;
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
            b[i][j] = b[i][j - 1] + a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ans += get(0, i, j) * get(1, i, j);
            ans %= M;
        }
    }
    printf("%lld", ans);
}