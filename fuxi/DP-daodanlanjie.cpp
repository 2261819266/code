#include <cstdio>

const int maxn = 100005;
int a[maxn], pre1[maxn], f1[maxn], pre2[maxn], f2[maxn], c, d, e, n;

int main() {
    scanf("%d", &n);
    for (c = 1; c <= n; c++)
        scanf("%d", &a[c]);
    for (c = 1; c <= n; c++) {
        pre1[c] = 0;
        for (d = 1; d < c; d++)
            if (a[c] <= a[d] && f1[pre1[c]] < f1[d])
                pre1[c] = d;
        f1[c] = f1[pre1[c]] + 1;
        if (f1[c] > f1[e])
            e = c;
    }
    printf("%d\n", f1[e]);
    for (c = 1; c <= n; c++) {
        pre2[c] = 0;
        for (d = 1; d < c; d++)
            if (a[c] > a[d] && f2[pre2[c]] < f2[d])
                pre2[c] = d;
        f2[c] = f2[pre2[c]] + 1;
        if (f2[c] > f2[e])
            e = c;
    }
    printf("%d\n", f2[e]);
}