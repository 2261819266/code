#include <cstdio>
#define ll long long

#ifdef LOCAL
const int maxn = 1e0 + 3;
#else
const int maxn = 1e5 + 9;
#endif
ll p;

struct SegTree {
#define ls (k << 1)
#define rs (ls | 1)
#define Def int mid = (l + r) / 2;
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
#define Ms 1, 1, n
#define num (r - l + 1)
#define lm (mid - l + 1)
#define rm (num - lm)
#define updata a[k] = a[ls] + a[rs];
#define passk pass(k, l, r);
#define mod(x) (x = (x % p + p) % p)
	ll a[maxn << 2], b[maxn << 2];

	inline void pass(int k, int l, int r) {
		Def
		mod(a[k]);
		b[ls] *= b[k], b[rs] *= b[k];
		a[ls] *= b[k], a[rs] *= b[k];
		mod(a[ls]), mod(a[rs]);
		b[k] = 1;
		a[ls] += (a[k] - a[ls] - a[rs] + p) % p / num * lm;
		a[rs] = a[k] - a[ls];
		mod(a[ls]), mod(a[rs]);

	}

	ll modify(int k, int l, int r, int i, int x) {
		b[k] = 1;
		if (l == r) return a[k] = x % p;
		Def
		i <= mid ? modify(Ls, i, x) : modify(Rs, i, x);
		return updata
	}

	ll add(int k, int l, int r, int L, int R, int x) {
		if (l >= L && r <= R) return a[k] = (a[k] + x * num) % p;
		if (l > R || L > r) return 0;
		Def passk
		add(Ls, L, R, x), add(Rs, L, R, x);
		return updata
	}

	ll mul(int k, int l, int r, int L, int R, int x) {
		if (l >= L && r <= R) {
			a[k] *= x;
			mod(a[k]);
			b[k] *= x;
			mod(b[k]);
			return a[k];
		}
		if (l > R || L > r) return 0;
		passk
		Def
		mul(Ls, L, R, x), mul(Rs, L, R, x);
		return updata
	}

	ll query(int k, int l, int r, int L, int R) {
		if (l >= L && r <= R) return a[k];
		if (l > R || L > r) return 0;
		Def passk
		return (query(Ls, L, R) + query(Rs, L, R)) % p;
	}
} sgt;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	LOCALfo
#endif
	int n, m;
	scanf("%d%d%lld", &n, &m, &p);
	for (int i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		sgt.modify(Ms, i, x);
	}
	for (int i = 0; i < m; i++) {
		int kk, x, y;
		ll k;
		scanf("%d%d%d", &kk, &x, &y);
		kk == 3 ? printf("%lld\n", sgt.query(Ms, x, y)) : (scanf("%lld", &k), kk == 2 ? sgt.add(Ms, x, y, k) : sgt.mul(Ms, x, y, k));
	}
	return 0;
}

