#include <cstdio>

const int maxn = 1e5 + 8;
int a[maxn];

void P1970() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        if (a[i] == a[i - 1]) i--, n--;
    }
    int ans = 1;
    for (int i = 2; i < n; i++) {
        if ((a[i] - a[i - 1]) * 1.0 * (a[i] - a[i + 1]) > 0) 
            ans++;
    }
    if (n > 1) ans++;
    printf("%d", ans);
}


int main() {
#ifdef LOCAL
    LOCALfo
#endif
    P1970();
    return 0;
}