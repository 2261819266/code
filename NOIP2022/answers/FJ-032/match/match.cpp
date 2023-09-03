#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
typedef unsigned long long u64;
const int N = 250005;
int T, n, Q;
int a[N], b[N];
int f[3003][3333], g[3333][3333];
u64 t[3333][3333], sum[3333][3333], ans[3333][3333];
int main() {
    freopen("match.in", "r", stdin);
    freopen("match.out", "w", stdout);
    scanf("%d%d", &T, &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);
    for(int i = 1; i <= n; ++i) {
        f[i][i] = a[i];
        g[i][i] = b[i];
        sum[i][i] = t[i][i] = (u64) a[i] * b[i];
    
        for(int j = i + 1; j <= n; ++j) {
            g[i][j] = std::max(g[i][j - 1], b[j]);
            f[i][j] = std::max(f[i][j - 1], a[j]);
            t[i][j] = (u64) f[i][j] * g[i][j];
            sum[i][j] = sum[i][j - 1] + t[i][j];
        }
        ans[i][i] = t[i][i];
    }
    for(int i = 1; i < n; ++i) {
        for(int l = 1; l + i <= n; ++l) {
            int r = l + i;
            ans[l][r] = ans[l + 1][r] + sum[l][r];
        }
    }
    scanf("%d", &Q);
    for(int i = 1; i <= Q; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%llu\n", ans[l][r]);
    }   
    return 0;   
}
