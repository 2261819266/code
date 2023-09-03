#include <cstdio>
#include <algorithm>
#define f(x, y, z) for (auto x = y, __ = z; x < __; ++x)
#define ll long long

const int maxn = 1e5 + 8;
int a[maxn], n;

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d", &n);
    ll ans = 0;
    f (i, 1, n + 1) {
        scanf("%d", a + i) ;
        ans += std::max(0, a[i] - a[i - 1]);
    }
    printf("%lld", ans);
}