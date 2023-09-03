// 动态开点线段树
const int maxn = 1e5 + 8;

struct SegTree {
#define ls a[k].l
#define rs a[k].r
#define Def int mid = (l + r) / 2;
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
#define updata a[k].s = a[ls].s + a[rs].s;
    struct Node {
        int s, l, r;
    } a[maxn << 4];
    int cnt = 1;
    int modify(int k, int l, int r, int i, int x) {
        if (l == r) return a[k].s = x;
        Def 
        if (!(i <= mid ? ls : rs)) (i <= mid ? ls : rs) = ++cnt;
        i <= mid ? modify(Ls, i, x) : modify(Rs, i, x);
        return updata;
    }

    int query(int k, int l, int r, int K) {
        if (l == r) return l;
        Def 
        return K <= a[ls].s ? query(Ls, K) : query(Rs, K - a[ls].s);
    }
} sgt;