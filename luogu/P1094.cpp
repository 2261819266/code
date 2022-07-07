#include <cstdio>
#include <algorithm>

const int maxn = 3e4 + 8;
int n, w, a[maxn];

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d", &w, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    std::sort(a, a + n, [](int x, int y) { return x > y; });
    int ans = 0;
    for (int i = 0, j = n - 1; i <= j; i++) {
        if (a[i] + a[j] <= w) j--;
        ans++;
    }
    printf("%d", ans);
}