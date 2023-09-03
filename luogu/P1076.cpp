#include <cstdio>

const int maxn = 1e4 + 8, maxm = 108, M = 20123;
int num[maxn], a[maxn][maxm], k[maxn][maxm];

void P1076() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d%d", &k[i][j], &a[i][j]);
            num[i] += k[i][j];
            // printf("%d ", k[i][j]);
        }
        // putchar('\n');
    }
    int x, ans = 0;
    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
        int t = a[i][x];
        // printf("%d ", t);
        ans += t;
        ans %= M;
        t = (t - 1) % num[i] + 1;
        // if (!t) t = num[i];
        // x--;
        for (int j = 0; ; x++) {
            if (x == m) x = 0;
            j += k[i][x];
            if (j == t) break;
        }
    }
    printf("%d", ans);
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    P1076();
    return 0;
}