#include <cstdio>

#define ll long long
const int maxn = 4e5 + 8;

struct SegTree {
#define ls (k << 1)
#define rs (ls | 1)
#define mid ((l + r) >> 1)
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
#define updata a[k] = a[ls] + a[rs]
#define lm (mid - l + 1)
#define rm (r - mid)
#define num (r - l + 1)
    ll a[maxn], b[maxn];
    ll modify(int k, int l, int r, int i, ll x) {
        if (l == r) return a[k] = x;
        i <= mid ? modify(Ls, i, x) : modify(Rs, i, x);
        return updata;
    }

    void pass(int k, int l, int r) {
        b[ls] += b[k];
        b[rs] += b[k];
        a[ls] += b[k] * lm;
        a[rs] += b[k] * rm;
        b[k] = 0;
    }

    ll add(int k, int l, int r, int L, int R, ll x) {
        if (l >= L && r <= R) return b[k] += x, a[k] += x * num;
        if (l > R || L > r) return 0;
        pass(k, l, r);
        add(Ls, L, R, x);
        add(Rs, L, R, x);
        return updata;
    }

    ll query(int k, int l, int r, int L, int R) {
        if (l >= L && r <= R) return a[k];
        if (l > R || L > r) return 0;
        pass(k, l, r);
        ll y = query(Ls, L, R) + query(Rs, L, R);
        return y;
    }
} a;

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        ll x;
        scanf("%lld", &x);
        a.modify(1, 1, n, i, x);
    }
    for (int i = 0; i < m; i++) {
        ll k, x, y, z;
        scanf("%lld%lld%lld", &k, &x, &y);
        if (k == 1) {
            scanf("%lld", &z);
            a.add(1, 1, n, x, y, z);
        } else {
            printf("%lld\n", a.query(1, 1, n, x, y));
        }
    }
}

int main() {
    solve();
    return 0;
}
