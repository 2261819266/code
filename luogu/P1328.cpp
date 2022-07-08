#include <cstdio>
#include <cstring>
#define f(x, y, z) for (auto x = (y), __ = (z); x < __; x++)

int f[5][5] = {
    {0, 2, 1, 1, 2},
    {1, 0, 2, 1, 2},
    {2, 1, 0, 2, 1},
    {2, 2, 1, 0, 1},
    {1, 1, 2, 2, 0}
};

const int maxn = 1000;
int n, na, nb;
char a[maxn], b[maxn];

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d%d", &n, &na, &nb);
    f(i, 0, na) {
        int x;
        scanf("%d", &x);
        sprintf(a + strlen(a), "%d", x);
    }
    f(i, 0, nb) {
        int x;
        scanf("%d", &x);
        sprintf(b + strlen(b), "%d", x);
    }
    while (strlen(a) < n) sprintf(a + strlen(a), "%s", a);
    while (strlen(b) < n) sprintf(b + strlen(b), "%s", b);
    int ans[3] = {};
    f(i, 0, n) {
        ans[f[a[i] - '0'][b[i] - '0']]++;
    }
    printf("%d %d", ans[1], ans[2]);
}