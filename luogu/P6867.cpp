#include <cstdio>
#define ll long long

const int maxn = 5005;
ll a[maxn][maxn], l[maxn * maxn], r[maxn * maxn];

ll z[maxn][maxn], cycle;

ll c, d, e, n;
ll k;

int main() {
#ifdef LOCAL
    freopen("E:\\code\\in.in", "r", stdin);
    freopen("E:\\code\\out.out", "w", stdout);
#endif

    scanf("%lld%lld", &n, &k);
    for (c = 1; c <= n; c++)
        for (d = 1; d <= n; d++)
            scanf("%lld", &a[c][d]);

    c = 1;
    l[c] = 1, r[1] = 2, z[2][1] = 1;
    while (true) {
        if (c == k) {
            printf("%lld", l[c]);
            return 0;
        }
        ll u = l[c], v = r[c];
        c++;
        if (z[l[c]][r[c]]) {
            d = z[l[c]][r[c]];
            break;
        }
        l[c] = v;
        r[c] = a[v][u];
        z[r[c]][l[c]] = c;
    }
    cycle = c - d;
    printf("%lld", (k - d) % cycle + d);
}
