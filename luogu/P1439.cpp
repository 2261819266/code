#include <cstdio>
#include <algorithm>

const int maxn = 1e5 + 8;
int a[maxn], b[maxn], f[maxn], t[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        t[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", b + i);
        b[i] = t[b[i]];
        // printf("%d ", b[i]);
    }

    f[1] = b[1];
    int len = 1;
    for (int i = 2; i <= n; i++) {
        if (b[i] > f[len]) f[++len] = b[i];
        else {
            int k = std::lower_bound(f, f + len, b[i]) - f;
            f[k] = std::min(f[k], b[i]);
        }
    }
    printf("%d", len);
}