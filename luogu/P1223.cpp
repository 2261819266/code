#include <algorithm>
#include <cstdio>
#define ll long long

struct P1223 {
    ll data, add;
    /* data */
} a[10005];

bool cmp(P1223 a, P1223 b) { return a.data < b.data; }

ll b, c, d, e, n;

int main() {
    // freopen("P1223_3.in", "r", stdin);
    // freopen("P1223_3.out", "w", stdout);
    scanf("%d", &n);
    for (c = 0; c < n; c++)
        scanf("%lld", &a[c].data), a[c].add = c;

    std::sort(a, a + n, cmp);

    printf("%lld ", a[0].add + 1);
    for (c = 1; c < n; c++) {
        printf("%lld ", a[c].add + 1);
        d += a[c - 1].data;
        e += d;
    }
    printf("\n");

    printf("%.2lf", e * 1.0 / n);
}