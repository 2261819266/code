#include <cstdio>

const int maxn = 2e5 + 8;

class SegmentTree {
#define ls (k << 1)
#define rs (ls | 1)
#define mid ((l + r) / 2)
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
#define updata a[k] = a[ls] + a[rs];
#define lm (mid - l + 1)
#define rm (r - mid)
#define num (r - l + 1)
public:
    int a[maxn << 2], b[maxn << 2];
    void pushdown(int k, int l, int r) {
        if (b[k]) {
            a[ls] = lm - a[ls];
            a[rs] = rm - a[rs];
            b[ls] ^= 1;
            b[rs] ^= 1;
            b[k] = 0;
        }
    }

    int add(int k, int l, int r, int L, int R) {
        if (L <= l && r <= R) return a[k] = num - a[k], b[k] ^= 1;
        if (l > R || L > r) return 0;
        pushdown(k, l, r);
        add(Ls, L, R);
        add(Rs, L, R);
        return updata
    }

    int query(int k, int l, int r, int L, int R) {
        if (L <= l && r <= R) return a[k];
        if (l > R || L > r) return 0;
        pushdown(k, l, r);
        return query(Ls, L, R) + query(Rs, L, R);
    }
} a;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (x == 0) {
            a.add(1, 1, n, y, z);
        } else {
            printf("%d\n", a.query(1, 1, n, y, z));
        }
    }
}
