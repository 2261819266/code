#include <cstdio>
#define ll long long

const int maxn = 1e5 + 9;

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
#define pass a[ls] += (a[k] - a[ls] - a[rs]) / num * lm, a[rs] = a[k] - a[ls];
#define updata a[k] = a[ls] + a[rs];
	ll a[maxn << 2];
	ll modify(int k, int l, int r, int i, int x) {
		if (l == r) return a[k] = x;
		Def
		i <= mid ? modify(Ls, i, x) : modify(Rs, i, x);
		return updata
	}

	ll add(int k, int l, int r, int L, int R, int x) {
		if (l >= L && r <= R) return a[k] += x * num;
		if (l > R || L > r) return 0;
		Def pass
		add(Ls, L, R, x), add(Rs, L, R, x);
		return updata
	}

	ll query(int k, int l, int r, int L, int R) {
		if (l >= L && r <= R) return a[k];
		if (l > R || L > r) return 0;
		Def pass
		return query(Ls, L, R) + query(Rs, L, R);
	}
} sgt;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	LOCALfo
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		sgt.modify(Ms, i, x);
	}
	for (int i = 0; i < m; i++) {
		int kk, x, y;
		ll k;
		scanf("%d%d%d", &kk, &x, &y);
		kk == 2 ? printf("%lld\n", sgt.query(Ms, x, y)) : (scanf("%lld", &k), sgt.add(Ms, x, y, k));
	}
	return 0;
}

