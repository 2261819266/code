#include <cstdio>
#include <algorithm>
#include <cmath>
#define f(x, y, z) for (auto x = y, __ = z; x < __; ++x)

const int maxn = 3e4 + 8;
int n, x, y;

using std::min;

int getDepth(int x, int y) { return min(min(x - 1, y - 1), min(n - x, n - y)); }

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d%d", &n, &x, &y);
    int now = 1, nx = 1, ny = 1, nn = n - 1;
    f(i, 0, getDepth(x, y)) {
        now += 4 * (n - 2 * i - 1);
        nx++, ny++, nn -= 2;
    }
    if (nx != x) {
        now += nn;
        nx += nn;
        if (ny != y) {
            now += nn;
            ny += nn;
            if (nx != x) {
                now += nn;
                nx -= nn;
            }
        }
    }
    now += abs(x - nx) + abs(y - ny);
    printf("%d", now);
}