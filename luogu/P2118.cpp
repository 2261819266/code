#include <cstdio>
#include <algorithm>
#define f(x, y, z) for (auto x = y, __ = z; x < __; ++x)

int a, b, x, y, l;

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d%d", &a, &b, &l);
    double s = a * 1.0 / b, ans = 1000;
    f(i, 1, l + 1) {
        f(j, 1, l + 1) {
            double k = i * 1.0 / j - s;
            if (k < 0) break;
            if (std::__gcd(i, j) - 1) continue;
            if (k < ans) ans = k, x = i, y = j;
        }
    }
    printf("%d %d", x, y);
}