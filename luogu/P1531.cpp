#include <cstdio>
#include <algorithm>

const int maxn = 2e5 + 8;
struct SegTree {
#define ls (k << 1)
#define rs (ls | 1)
#define Def int mid = (l + r) / 2;
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
    int a[maxn << 2];
    int modify(int k, int l, int r, int i, int x) {
        if (l == r) return a[k] = std::max(a[k], x);
        Def
        i <= mid ? modify(Ls, i, x) : modify(Rs, i, x);
        return a[k] = std::max(a[ls], a[rs]);
    }

    int query(int k, int l, int r, int L, int R) {
        if (l > R || L > r) return 0;
        if (l >= L && r <= R) return a[k];
        Def
        return std::max(query(Ls, L, R), query(Rs, L, R));
    }
} sgt;

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        sgt.modify(1, 1, n, i + 1, x);
    }
    for (int i = 0; i < m; i++) {
        char x[2];
        int y, z;
        scanf("%s%d%d", &x, &y, &z);
        if (*x == 'Q') printf("%d\n", sgt.query(1, 1, n, y, z));
        else sgt.modify(1, 1, n, y, z);
    }
}
