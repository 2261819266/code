#include <cstdio>
#define fo(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);

const int maxn = 2e4 + 8;
int a[maxn];

int main() {
    // fo(jump)
    int n, m, k1, k2;
    k1 = k2 = true;
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        scanf("%d", a + i);
        if (a[i] != n - i) k1 = false;
    }
    if (k1) {
        for (int i = 0; i < m; i++) {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            printf("%d\n", l < r);
        }
        return 0;
    }
}