#include <cstdio>

const int maxn = 10005;
int a[maxn], f[maxn], pre[maxn], c, d, e, n;

int main() {
    scanf("%d", &n);
    for (c = 1; c <= n; c++)
        scanf("%d", &a[c]);
    for (c = 1; c <= n; c++) {
        for (d = 1; d < c; d++)
            if (a[c] <= a[d] && f[pre[c]] < f[d])
                pre[c] = d;
        f[c] = f[pre[c]] + 1;
        if (f[c] > f[e])
            e = c;
    }
    printf("%d", f[e]);
}