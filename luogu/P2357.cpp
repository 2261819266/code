#include <algorithm>
#include <cmath>
#include <cstdio>
#define ll long long

const int maxn = 2e6 + 8;

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
	ll a[maxn << 2], b[maxn << 2];
	ll modify(int k, int l, int r, int i, ll x) {
		if (l == r)
			return a[k] = x;
		Def i <= mid ? modify(Ls, i, x) : modify(Rs, i, x);
		return updata
	}

	void pushup(int k, int l, int r) {
		Def
		a[ls] += b[k] * lm;
		a[rs] += b[k] * rm;
		b[ls] += b[k];
		b[rs] += b[k];
		b[k] = 0;
	}

	ll add(int k, int l, int r, int L, int R, ll x) {
		if (l >= L && r <= R)
			return a[k] += x * num, b[k] += x;
		if (l > R || L > r)
			return 0;
		Def
			pushup(k, l, r);
			add(Ls, L, R, x),
			add(Rs, L, R, x);
		return updata
	}

	ll query(int k, int l, int r, int L, int R) {
		if (l >= L && r <= R)
			return a[k];
		if (l > R || L > r)
			return 0;
		Def pushup(k, l, r);
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
		sgt.modify(1, 1, n, i, x);
	}
	for (int i = 0; i < m; i++) {
		int kk, x, y;
		ll k;
		scanf("%d", &kk);
		switch (kk) {
			case 1:
				scanf("%d%d%lld", &x, &y, &k), sgt.add(1, 1, n, x, y, k);
				break;

			case 2:
				scanf("%lld", &k);
				sgt.add(1, 1, n, 1, 1, k);
				break;

			case 3:
				scanf("%lld", &k);
				sgt.add(1, 1, n, 1, 1, -k);
				break;

			case 4:
				scanf("%d%d", &x, &y);
				printf("%lld\n", sgt.query(1, 1, n, x, y));
				break;

			case 5:
				printf("%lld\n", sgt.query(1, 1, n, 1, 1));
				break;

			default:
				break;
		}
	}
	return 0;
}
