#include <cstdio>
#include <algorithm>
#include <cmath>

const int maxn = 1e6 + 8;
int a[maxn];

void U231373() {
    int n, x, p, q, now = 0, sleep = 0, task = 1;
    scanf("%d%d%d%d", &n, &x, &p, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    int i;
    for (i = 1; task <= n; i++) {
        int need = std::max(1, (int)ceil(i * 1.0 * x * p / q) - now);
        int y = x - need;
        while (y >= a[task] && task <= n) {
            y -= a[task];
            task++;
        }
        now += y + need;
    }
    printf("%d", i - 1);
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    U231373();
    return 0;
}

