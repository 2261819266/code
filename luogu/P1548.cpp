#include <cstdio>

int n, m;

int main() { 
#ifdef LOCAL
    LOCALfo
#endif
    int ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = n, j = m; i > 0 && j > 0; i--, j--) {
        ans += i * j;
    }
    int a = n * (1 + n) / 2;
    int b = m * (1 + m) / 2;
    printf("%d %d", ans, a * b - ans);
}