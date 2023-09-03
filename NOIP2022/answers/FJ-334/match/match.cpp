#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int T, n, q, l, r, maxa[3005][3005], maxb[3005][3005];
ull ans[3005][3005];

int main() {
    freopen("match.in", "r", stdin);
    freopen("match.out", "w", stdout);
    
    scanf("%d %d", &T, &n);
    
    for (int i = 1; i <= n; ++i)
        scanf("%d", &maxa[i][i]);
    
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &maxb[i][i]);
        ans[i][i] = maxa[i][i] * maxb[i][i];
    }
    
    for (int len = 1; len < n; ++len)
        for (int i = 1; i <= n - len; ++i) {
            maxa[i][i + len] = max(maxa[i][i + len - 1], maxa[i + 1][i + len]);
            maxb[i][i + len] = max(maxb[i][i + len - 1], maxb[i + 1][i + len]);
            ans[i][i + len] = ans[i][i + len - 1] + ans[i + 1][i + len] - ans[i + 1][i + len - 1] + maxa[i][i + len] * maxb[i][i + len];
        }
    
    scanf("%d", &q);
    
    while (q--) {
        scanf("%d %d", &l, &r);
        printf("%llu\n", ans[l][r]);
    }
    
    return 0;
}
