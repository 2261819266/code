#include <cstdio>

const int maxn = 1e4 + 5;
const int M = 998244353;

#define ll long long
ll a[maxn], t[maxn][maxn], sum[maxn];
int n;
int main() {
    
#ifndef LOCAL
    #define fo(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);
    fo(brother)
#endif
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%lld", a + i);
    }
    for (int i = n - 1; i > 0; i--) {
        for (int j = 1; j <= a[i]; j++) {
            
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += t[0][i];
        ans %= M;
        // printf("%d\n", t[i]);
    }
    printf("%lld", ans);
}