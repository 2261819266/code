#include <cstdio>
#include <algorithm>
#include <cstring>

const int maxn = 121;
int a[maxn][maxn], sum[maxn][maxn];

int main() {
#ifdef LOCAL
    LOCALfo
#endif  
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            ans = std::max(ans, a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            memset(sum, 0, sizeof(sum));
            for (int k = i; k <= n; k++) {
                for (int l = j; l <= n; l++) {
                    if (i == k && j == l) sum [i][j] = a[i][j];
                    else sum[k][l] = sum[k - 1][l] + sum[k][l - 1] - sum[k - 1][l - 1] + a[k][l];
                    ans = std::max(ans, sum[k][l]);
                }
            }
        }
    }
    printf("%d", ans);
}