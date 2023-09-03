#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define f(x, y, z) for (int x = y, __ = z; x < __; ++x)
#define mid (l + r) / 2

const int maxn = 2e5 + 8;

int a[maxn], b[maxn], root[maxn];
std::vector<int> v;
int ls[maxn << 5], rs[maxn << 5], s[maxn << 5];
int n, m, cnt;

int modify(int pre, int l, int r, int x) {
    int p = ++cnt;
    ls[p] = ls[pre], rs[p] = rs[pre], s[p] = s[pre];
    if (l == r) {
        s[p]++;
        return p;
    }
    if (x <= mid) 
        ls[p] = modify(ls[pre], l, mid, x);
    else 
        rs[p] = modify(rs[pre], mid + 1, r, x);
    s[p] = s[ls[p]] + s[rs[p]];
    return p;
}

int query(int u, int v, int l, int r, int k) {
    if (l == r) return l;
    int x = s[ls[v]] - s[ls[u]];
    // int l = 
    return k <= x ? query(ls[u], ls[v], l, mid, k) : query(rs[u], rs[v], mid + 1, r, k - x);
}

int main() {
#ifdef LOCAL    
    LOCALfo
#endif
    scanf("%d%d", &n, &m);
    f(i, 1, n + 1) {
        scanf("%d", a + i);
        b[i] = a[i];
    }
    std::sort(b + 1, b + n + 1);
    b[0] = -1;
    f(i, 1, n + 1) {
        if (b[i] != b[i - 1]) v.push_back(b[i]);
    }
    f(i, 1, n + 1) {
        root[i] = modify(root[i - 1], 1, n, std::lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1);
    }


    f(i, 0, m) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", v[query(root[l - 1], root[r], 1, n, k) - 1]);
    }
    return 0;
}