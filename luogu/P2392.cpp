#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int tx(int *a, int n) {
    int b1 = 0, b2 = 0, c, d, e;
    if (n == 1) {
        return a[0];
    }
    if (n == 2) {
        return max(a[0], a[1]);
    }
    sort(a, a + n);
    for (c = n - 1; c >= 0; c--) {
        (b1 <= b2 ? b1 : b2) += a[c];
    }
    return max(b1, b2);
}
int a[100], b, c, d, e, n[4];
int main() {
    for (c = 0; c < 4; c++) {
        scanf("%d", &n[c]);
    }
    for (c = 0; c < 4; c++) {
        for (d = 0; d < n[c]; d++) {
            scanf("%d", &a[d]);
        }
        e += tx(a, n[c]);
    }
    printf("%d", e);
}