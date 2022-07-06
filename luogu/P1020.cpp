#include <cmath>
#include <cstdio>
#include <string.h>

int c_i(const char *a) {
    int c, e = 0, n = strlen(a);
    for (c = 0; c < n; c++) {
        e += (a[c] - '0') * pow(10, n - c - 1);
    }
    return e;
}

const int maxn = 100005;
int a[maxn], pre1[maxn], f1[maxn], pre2[maxn], f2[maxn], c, d, e, n;
char s[maxn*10], a1[maxn*10];

int main() {
    gets(s);
    int x;
    for (c = 0; c <= strlen(s); x++, c++) {
        if (s[c] == ' '||c==strlen(s))
            a1[x]='\0',a[++n] = c_i(a1), x = -1;
        else
            a1[x] = s[c];
    }
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
    e=0;
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