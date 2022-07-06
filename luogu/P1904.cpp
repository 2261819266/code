#include <cstdio>
#include <algorithm>
#define ll long long

const int maxn = 1e4 + 8;

struct SegTree {
#define ls (k << 1)
#define rs (ls | 1)
#define Def int mid = (l + r) / 2;
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
	ll a[maxn << 4], b[maxn << 4];
	void modify(int k, int l, int r, int L, int R, ll x) {
		if (l >= L && r <= R) {
			if (l == r)
				a[k] = std::max(a[k], x);
			else
				b[k] = std::max(b[k], x);
			return;
		}
		if (l > R || L > r)
			return;
		Def
		modify(Ls, L, R, x);
		modify(Rs, L, R, x);
	}

	void pushup(int k) {
		b[ls] = std::max(b[ls], b[k]);
		b[rs] = std::max(b[rs], b[k]);
	}

	ll find(int k, int l, int r, int i) {
		if (l == r) return a[k] = std::max(a[k], b[k]);
		Def
		pushup(k);
		if (i <= mid)
			return find(Ls, i);
		else
			return find(Rs, i);
	}
} sgt;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	LOCALfo
#endif
	int x, z;
	ll y;
	while (scanf("%d", &x) != EOF) {
		scanf("%lld%d", &y, &z);
		sgt.modify(1, 1, maxn, x * 2, z * 2, y);
	}
	ll now = -1, ne;
	for (int i = 2; i <= maxn * 2; i++) {
		ne = sgt.find(1, 1, maxn, i);
		if (ne != now)
			printf("%d %lld ", i / 2, ne);
		now = ne;
	}
	return 0;
}

