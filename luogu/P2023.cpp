#include <cstdio>
#include <cstring>
#define ll long long

const int maxn = 1e5 + 8;
int p;
struct SegTree {
#define ls (k << 1)
#define rs (ls | 1)
#define Def int mid = (l + r) / 2;
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
#define updata a[k] = a[ls] + a[rs];
#define num (r - l + 1)
#define lm (mid - l + 1)
#define rm (num - lm)
#define push pushdown(k, l, r);
	ll a[maxn << 2], b[maxn << 2], c[maxn << 2];
	SegTree() {
		for (int i = 0; i < maxn << 2; i++) 
			b[i] = 1;
	}

	ll modify(int k, int l, int r, int i, ll x) {
		if (l == r) return a[k] = x % p;
		Def i <= mid ? modify(Ls, i, x) : modify(Rs, i, x);
		return updata
	}

	void pushdown(int k, int l, int r) {
		Def
		ll x = b[k], y = c[k];
		a[ls] *= x, a[rs] *= x;
		a[ls] += y * lm, a[rs] += y * rm;
		a[ls] %= p, a[rs] %= p;
		b[ls] *= x, b[rs] *= x;
		c[ls] *= x, c[rs] *= x;
		c[ls] += y, c[rs] += y;
		b[ls] %= p, b[rs] %= p;
		c[ls] %= p, c[rs] %= p;
		b[k] = 1, c[k] = 0;
	}

	ll add(int k, int l, int r, int L, int R, ll x) {
		if (l > R || L > r) return 0;
		if (l >= L && r <= R) 
			return a[k] += num * x, c[k] += x, a[k] %= p, c[k] %= p;
		Def push
		add(Ls, L, R, x), add(Rs, L, R, x);
		return a[k] = (a[ls] + a[rs]) % p;
	}

	ll mul(int k, int l, int r, int L, int R, ll x) {
		if (l > R || L > r) return 0;
		if (l >= L && r <= R) 
			return a[k] *= x, b[k] *= x, c[k] *= x, a[k] %= p, b[k] %= p, c[k] %= p;
		Def push
		mul(Ls, L, R, x), mul(Rs, L, R, x);
		return a[k] = (a[ls] + a[rs]) % p;
	}

	ll query(int k, int l, int r, int L, int R) {
		if (l > R || L > r) return 0;
		if (l >= L && r <= R) return a[k];
		Def push
		return (query(Ls, L, R) + query(Rs, L, R)) % p;
	}
} sgt;

int  main() {
#ifdef LOCAL
	LOCALfo
#endif
	int n, m;
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		sgt.modify(1, 1, n, i, x % p);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int op, l, r;
		ll x;
		scanf("%d%d%d", &op, &l, &r);
		if (op == 3) printf("%lld\n", sgt.query(1, 1, n, l, r));
		else {
			scanf("%lld", &x);
			x %= p;
			op == 1 ? sgt.mul(1, 1, n, l, r, x) : sgt.add(1, 1, n, l, r, x);
		}
	}
}
