#include <cstdio>
#include <algorithm>

const int maxn = 508;
int a[maxn][maxn], b[maxn];

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            a[j][i] = a[i][j];
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         printf("%d\t", a[i][j]);
    //     }
    //     putchar('\n');
    // }
    auto f = [](int x, int y) { return x > y; };
    for (int i = 1; i <= n; i++) {
        std::sort(a[i] + 1, a[i] + n + 1, f);
        b[i] = a[i][2];
    }
    std::sort(b + 1, b + n + 1, f);
    printf("1\n%d", b[1]);
}