#include <cstdio>

const int maxn = 2e5 + 8, M = 10007;
int c[maxn], a[maxn];
long long suma[maxn], sumt[maxn], t[maxn];

void P2671() {
    int n, m;
    long long ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        a[i] %= M;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", c + i);
        c[i] += i % 2 * m;
        suma[c[i]] += a[i];
        suma[c[i]] %= M;
        sumt[c[i]] += i;
        sumt[c[i]] %= M;
        t[c[i]]++;
    }
    for (int i = 1; i <= m * 2; i++) {
        ans += suma[i] * sumt[i];
        ans %= M;
    }
    for (int i = 1; i <= n; i++) {
        ans += (t[c[i]] - 2) * i * a[i];
        if (ans < 0) ans += M * M;
        ans %= M;
    }
    printf("%lld", ans);
}


int main() {
#ifdef LOCAL
    LOCALfo
#endif
    P2671();
    return 0;
}
// #include <con>