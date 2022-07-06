#include <cstdio>

const int maxn = 5005, inf = 0x7fffffff;
int a[maxn], f[maxn], pre[maxn], ans[maxn], n, c, d, e;

int main() {
    scanf("%d", &n);
    for (c = 1; c <= n; c++)
        scanf("%d", &a[c]);
    a[0] = -inf;
    for (c = 1; c <= n; c++) {
        for (d = 1; d < c; d++)
            if (a[c] >= a[d] && f[d] > f[pre[c]])
                pre[c] = d;
        f[c] = f[pre[c]] + 1;
        if (f[c] > f[e])
            e = c;
    }
    printf("%d\n", f[e]);
    int tail = 0;
    while (e)
        ans[tail++] = a[e], e = pre[e];
    while (tail)
        printf("%d ", ans[--tail]);
}