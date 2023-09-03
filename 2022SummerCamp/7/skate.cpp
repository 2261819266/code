#include <cstdio>
#include <algorithm>
// #include <type_traits>

const int maxn = 3e3 + 8;
struct pair {
    int f, s;
};
pair fa[maxn][maxn];
int a[maxn];

int main() {
    freopen("skate.in", "r", stdin);
    freopen("skate.out", "w", stdout);
    int n;
    scanf("%d", &n);
    if (n >= maxn) {    
        for (int i = 0; i < n;  i++) {
            scanf("%d", a + i);

        }
        int q;
        scanf("%d", &q);
        while (q--) {
            int b, c, d, e;
            scanf("%d%d%d%d", &b, &c, &d, &e);
            int x = b - c, y = d - e;
            if (x == y) {
                printf("%d %d\n", n - x);
            } else {
                printf("%d %d\n", 0, std::min(x, y));
            }
        }
        return 0;
    }
    fa[0][0] = {0, 0};
    for (int i = 1; i <= n; i++) {
        fa[i][i] = {i - 1, i - 1};
        a[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        for (int j = n - x; j < n; j++) {
            a[j + 1]--;
            fa[j + 1][a[j + 1]] = {j, a[j]};
        } 
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        pair b, c;
        scanf("%d%d%d%d", &b.f, &b.s, &c.f, &c.s);
        if (b.f < c.f) std::swap(b, c);
        while (b.f != c.f) {
            b = fa[b.f][b.s];
        }
        while (b.s != c.s) {
            b = fa[b.f][b.s];
            c = fa[c.f][c.s];
        }
        printf("%d %d\n", b.f, b.s);
    }
    return 0;
}