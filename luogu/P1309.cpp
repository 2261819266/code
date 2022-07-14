#include <cstdio>
#include <algorithm>
#define f(x, y, z) for (auto x = y, __ = z; x < __; ++x)

const int maxn = 2e5 + 8;
struct Node {
    int id, s, w;
    bool operator<(const Node &b) { 
        return s == b.s ? id < b.id : s > b.s;
    }
} a[maxn], b[2][maxn];

int main() {
#ifdef LOCAL
    LOCALfo
#endif  
    int n, r, k;
    scanf("%d%d%d", &n, &r, &k);
    n *= 2;
    f(i, 1, n + 1) scanf("%d", &a[i].s), a[i].id = i;
    f(i, 1, n + 1) scanf("%d", &a[i].w);
    std::sort(a + 1, a + n + 1);
    f(i, 0, r) {
        f(i, 0, n / 2) {
            int k = a[i * 2 + 1].w < a[i * 2 + 2].w;
            a[i * 2 + 1 + k].s++;
            b[1][i + 1] = a[i * 2 + 1 + k];
            b[0][i + 1] = a[i * 2 + 1 + !k]; 
        }
        int num = n / 2;
        std::merge(b[0] + 1, b[0] + num + 1, b[1] + 1, b[1] + num + 1, a + 1);
    }
    printf("%d", a[k].id);
}
