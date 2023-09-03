#include <cstdio>
#include <algorithm>

const int maxn = 1e4 + 5;
int a[maxn], m, n;

void add() {
    int k;
    for (k = 0; a[k] < a[k + 1]; k++);
    for (int i = 0; i <= k; i++) {
        if (a[i] > a[k + 1]) {
            std::swap(a[i], a[k + 1]);
            break;
        }
    }
    std::sort(a, a + k + 1, [](int x, int y) { return x > y; });
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + n - i - 1);
    }
    for (int i = 0; i < m; i++) add();
    for (int i = 0; i < n; i++) {
        printf("%d ", a[n - i - 1]);
    }
}