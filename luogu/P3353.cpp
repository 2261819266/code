#include <cstdio>
#include <algorithm>

const int maxn = 1e5 + 5;
struct SegTree {
#define ls (k << 1)
#define rs (ls | 1)
#define Def int mid = (l + r) / 2;
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
    int a[maxn << 2];
    int modify(int k, int l, int r, int i, int x) {
        if (l == r) return a[k] += x;
        Def
        i <= mid ? modify(Ls, i, x) : modify(Rs, i, x);
        return a[k] = a[ls] + a[rs];
    }

    int query(int k, int l, int r, int L, int R) {
        if (l > R || L > r) return 0;
        if (l >= L && r <= R) return a[k];
        Def
        return query(Ls, L, R) + query(Rs, L, R);
    }
} sgt;

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        sgt.modify(1, 1, n, x, y);
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans = std::max(ans, sgt.query(1, 1, n, i, i + m - 1));
    }
    printf("%d", ans);
}
