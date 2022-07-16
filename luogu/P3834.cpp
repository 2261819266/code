#include <cstdio>
#include <algorithm>
#include <vector>
#define f(x, y, z) for (int x = y, __ = z; x < __; ++x)

const int maxn = 2e5 + 8;
struct Node {
    int l, r, v;
};
std::vector<int> v; 
int d[maxn];

int get(int x) {
    return std::lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

struct SegTree {
#define ls a[k].l
#define rs a[k].r
#define Def int mid = (l + r) / 2;
#define updata a[k].v = a[ls].v + a[rs].v;
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
    Node a[maxn * 40];
    int cnt = 0;
    int modify(int n, int i, int x) {
        return modify(++cnt, 1, n, i, x);
    }

    int modify(int k, int l, int r, int i, int x) {
        if (l == r) return a[k].v++;
        Def
        i <= mid ? (ls = ++cnt, modify(Ls, i, x)) : (rs = ++cnt, modify(Rs, i, x));
        return updata;
    }

    int ask(int k, int l, int r, int x) {
        if (l == r) return l;
        Def
        if (a[ls].v >= x) return ask(Ls, x);
        else return ask(Rs, x);
    }
} sgt;

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    f(i, 0, n) {
        scanf("%d", d + i);
        v.push_back(d[i]);
    }
    v.erase(std::unique(v.begin(), v.end()), v.end());
    f(i, 0, n) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        printf("%d\n", v[sgt.ask(int k, int l, int r, int x)])
    }
}