#include <cstdio>
#define f(x, y, z) for (int x = y, __ = z; x < __; ++x)

const int maxn = 5e5 + 8;
int a[maxn];
int n, m, L;

bool check(int x) {
    int j, k = 0;
    for (int i = 0; i <= n; ) {
        j = i + 1;
        while (a[j] - a[i] < x) j++, k++;
        i = j;
        if (k > m) return false;
    }
    return true;
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d%d", &L, &n, &m);
    a[n + 1] = L;
    f(i, 1, n + 1) {
        scanf("%d", a + i);
    }
    int l = 0, r = L + 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        check(mid) ? l = mid : r = mid - 1;
    }    
    printf("%d", l);
}