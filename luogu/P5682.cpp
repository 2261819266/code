#include <cstdio>
#include <algorithm>

const int maxn = 2e5 + 8;
int a[maxn];

bool cmp(int x, int y) { return x > y; }

int main() {
#ifdef LOCAL    
    LOCALfo
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    std::sort(a, a + n, cmp);
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) a[i] = 0;
    }
    std::sort(a, a + n, cmp);
    while (n > 0 && a[n - 1] == 0) n--;
    if (n == 1) printf("-1");
    else if (n == 2) printf("%d", a[0] % a[1]);
    else printf("%d", std::max(a[2] % a[0], a[0] % a[1]));
}