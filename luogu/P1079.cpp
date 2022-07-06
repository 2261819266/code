#include <cstdio>
#include <cstring>

const int maxn = 1e3 + 5;
char a[maxn], p[maxn];

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%s%s", p, a);
    int n = strlen(a), m = strlen(p);
    for (int i = 0; i < n; i++) {
        int k1 = a[i] % 0x20 - 1, k2 = p[i % m] % 0x20 - 1;
        int k = k1 - k2;
        if (k < 0) k += 26;
        char f = a[i] / 0x20 * 0x20 + 1 + k;
        printf("%c", f);
    }
}