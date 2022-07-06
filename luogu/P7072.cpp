#include <cstdio>
#include <algorithm>

const int maxn = 1000;
struct SegTree {
#define ls (k << 1)
#define rs (ls | 1)
#define Def int mid = (l + r) >> 1;
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
#define updata a[k] = a[ls] + a[rs];
    int a[maxn << 2];
    int modify(int k, int l, int r, int i) {
        if (l == r) return a[k]++;
        Def
        i <= mid ? modify(Ls, i) : modify(Rs, i);
        return updata
    }
    int find(int k, int l, int r, int i) {
        if (l == r) return l;
        Def 
        return i <= a[rs] ? find(Rs, i) : find(Ls, i - a[rs]); 
    }
} sgt;

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        sgt.modify(1, 0, maxn, x);
        printf("%d ", sgt.find(1, 0, maxn, std::max(1, i * m / 100)));
    }
}