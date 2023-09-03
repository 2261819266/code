#include <cstdio>

int k, m, n;

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d%d", &k, &n, &m);
    int num = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (!x && y) printf("%d ", i + 1), num++;
        else if (k / x * y >= m) printf("%d ", i + 1), num++;
    }
    if (!num) printf("-1");
}