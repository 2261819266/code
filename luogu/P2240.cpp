#include <algorithm>
#include <cstdio>

const int maxn = 1005;

struct P2240 {
    double m, v;
    double v_m;
    /* data */
} a[maxn];

bool cmp(P2240 a, P2240 b) { return a.v_m > b.v_m; }

int t, b, c, d, n;
double e;

int main() {
    scanf("%d%d", &n, &t);
    for (c = 0; c < n; c++)
        scanf("%lf%lf", &a[c].m, &a[c].v), a[c].v_m = (double)a[c].v / (double)a[c].m;
    std::sort(a, a + n, cmp);
    for (c = 0; c < n; c++) {
        if (a[c].m > t) {
            e += t * a[c].v_m;
            printf("%.2lf", e);
            return 0;
        }
        e+=a[c].v;
        t-=a[c].m;
    }
}