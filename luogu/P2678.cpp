#include <cstdio>
#include <queue>
#include <algorithm>
#define f(x, y, z) for (auto x = y, __ = z; x < z; ++x)

const int maxn = 5e4 + 8;
int a[maxn], d[maxn];
struct Node {
    int x;
    bool operator<(const Node &b) { return d[x] < d[b.x]; }
} b[maxn];

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n, m, l;
    scanf("%d%d%d", &l, &n, &m);
    a[n + 1] = l;
    f(i, 1, n + 1) scanf("%d", a + i), d[i - 1] = a[i] - a[i - 1], b[i] = {i};
    std::sort(b, b + n + 1);
    f(i, 0, m) {
        int x = b[0].x;
        int y;
        if (x == 0) y = 1;
        else if (x == n) y = n - 1;
        else y = d[x - 1] < d[x + 1] ? x - 1 : x + 1;
    }
}