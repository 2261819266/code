#include <cstdio>

int n, l, r;

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d%d", &n, &l, &r);
    int x, y;
    x = l / n;
    y = r / n;
    printf("%d", x == y ? r % n : n - 1);
}