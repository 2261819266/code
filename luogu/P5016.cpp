#include <cstdio>
#define ll long long
#define f(x, y, z) for (auto x = y, __ = z; x < __; ++x)
#define abs(x) ((x) < 0 ? -(x) : (x))

const int maxn = 1e5 + 8;
ll a[maxn], s1, s2, l, r, x;
int n, m, p1, p2;

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d", &n);
    f(i, 1, n + 1) scanf("%lld", a + i);
    scanf("%d%d%lld%lld", &m, &p1, &s1, &s2);
    a[p1] += s1;
    f(i, 1, n + 1) 
        x += a[i] * (m - i);
    ll ans = abs(x); int id = m;
    f(i, 1, n + 1) {
        if (abs(x + s2 * (m - i)) < ans)
            ans = abs(x + s2 * (m - i)), id = i;
    }
    printf("%d", id);
}