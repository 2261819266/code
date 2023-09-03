#include <algorithm>
#include <cstdio>

int a[1000], b[100], c, d, e, n, r;

int main() {
    scanf("%d%d", &n, &r);
    for (c = 0; c < n; c++)
        scanf("%d", &a[c]);

    std::sort(a, a + n);

    for (c = 0; c < n; c++) {
        std::sort(b, b + r);
        b[0] += a[c];
        e += b[0];
    }
    printf("%d", e);
}