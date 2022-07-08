#include <cstdio>
#include <algorithm>
#define f(x, y, z) for (auto x = y, __ = z; x < z; ++x)

const int maxn = 2e5 + 8;
int a[maxn];

int main() {
#ifdef LOCAL    
    LOCALfo
#endif
    int n;
    scanf("%d", &n);
    f(i, 0, n) {
        scanf("%d", a + i);
    }
    std::sort(a, a + n);
    int now = a[0], ans = 0;
    printf("%d ", now);
    f(i, 0, n) {
        if (a[i] - now) printf("%d\n%d ", ans, a[i]), ans = 1, now = a[i];
        else ans++;
    }
    printf("%d", ans);
}