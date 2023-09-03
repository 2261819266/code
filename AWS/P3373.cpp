#include <cstdio>
#include <vector>

typedef size_t ll;
const int maxn = 1e5 + 5;
ll M;

class SegTree {
#define ls (k << 1)
#define rs (ls | 1)
#define mid ((l + r) >> 1)
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
#define updata a[k] = a[ls] + a[rs];
#define lm (mid - l + 1)
#define rm (r - mid)
#define num (r - l + 1)
public:
    std::vector<ll> a, b, c;
    SegTree(int n) {
        a.assign(n << 2, 0);
        b.assign(n << 2, 1);
        c.assign(n << 2, 0);
    }

    ll modify(int k, int l, int r, int x, ll v) {
        if (l == r) return a[k] = v % M;
        x <= mid ? modify(Ls, x, v) : modify(Rs, x, v);
        return updata
    }

    void pushdown(int k, int l, int r) {
        a[ls] *= b[k];
        a[ls] += c[k] * lm;
        a[ls] %= M;

        a[rs] *= b[k];
        a[rs] += c[k] * rm;
        a[rs] %= M;

        b[ls] *= b[k];
        b[ls] %= M;
        b[rs] *= b[k];
        b[rs] %= M;

        c[ls] *= b[k];
        c[ls] += c[k];
        c[ls] %= M;

        c[rs] *= b[k];
        c[rs] += c[k];
        c[rs] %= M;

        b[k] = 1;
        c[k] = 0;
    }

    ll add(int k, int l, int r, int L, int R, ll v) {
        if (l > R || r < L) return a[k];
        if (L <= l && r <= R) return a[k] = (a[k] + v * num) % M, c[k] = (c[k] + v) % M;
        pushdown(k, l, r);
        add(Ls, L, R, v);
        add(Rs, L, R, v);
        return updata
    }

    ll multiply(int k, int l, int r, int L, int R, ll v) {
        if (l > R || r < L) return a[k];
        if (L <= l && r <= R) return a[k] = (a[k] * v) % M, b[k] = (b[k] * v) % M, c[k] = (c[k] * v) % M;
        pushdown(k, l, r);
        multiply(Ls, L, R, v);
        multiply(Rs, L, R, v);
        return updata
    }

    ll query(int k, int l, int r, int L, int R) {
        if (l > R || r < L) return 0;
        if (L <= l && r <= R) return a[k];
        pushdown(k, l, r);
        return (query(Ls, L, R) + query(Rs, L, R)) % M;
    }
} a(maxn);

int main() {
    ll n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    M = k;
    for (int i = 1; i <= n; i++) {
        ll x;
        scanf("%lld", &x);
        a.modify(1, 1, n, i, x);
    }

    while (m--) {
        ll k, x, y, z;
        scanf("%lld", &k);
        if (k == 1) {
            scanf("%lld%lld%lld", &x, &y, &z);
            a.multiply(1, 1, n, x, y, z);
        } else if (k == 2) {
            scanf("%lld%lld%lld", &x, &y, &z);
            a.add(1, 1, n, x, y, z);
        } else {
            scanf("%lld%lld", &x, &y);
            printf("%lld\n", a.query(1, 1, n, x, y));
        }
    }
}

