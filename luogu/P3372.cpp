#include <cstdio>
#define ll long long

const int maxn = 1e5 + 5;
int n, m;

struct node {
	ll sum, lazy;
	operator ll() const { return sum + lazy; }
	node operator=(ll x) { sum = x; return *this; }
	node operator+(ll x) const { return (node){sum + x, lazy}; }
	node &operator+=(ll x) { return *this = *this + x; }
};

class SegTree {
private:
#define ls (k << 1)
#define rs (ls | 1)
#define Def int mid = (l + r) / 2;
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
public:
	node data[maxn << 2];

	ll pass(int k, int l, int r) {
		Def
		int k1 = mid - l + 1, k2 = r - mid;
		data[ls].lazy += data[k].lazy / (k1 + k2) * k1;
		data[rs].lazy += data[k].lazy / (k1 + k2) * k2;
		ll res = data[k].lazy;
		data[k].lazy = 0;
		data[k] = (ll) data[ls] + (ll) data[rs];
		return res;
	}
public:
	ll modify(int k, int l, int r, int i, ll x) {
		int res;
		if (l == r)
			return res = data[k] = x;
		Def
		if (i <= mid)
			res = modify(Ls, i, x);
		else
			res = modify(Rs, i, x);
		data[k] = (ll) data[ls] + (ll) data[rs];
		return res;
	}

	ll modify(int i, ll x) {
		return modify(1, 1, n, i, x);
	}

	ll add(int k, int l, int r, int L, int R, ll x) {
		if (l >= L && r <= R){
			data[k].lazy += x * (r - l + 1);
			return x * (r - l + 1);
		}
		if (l > R || r < L)
			return 0;
		Def
		// if (l <= mid)
			add(Ls, L, R, x);
		// if (r > mid)
			add(Rs, L, R, x);
		data[k] = (ll) data[ls] + (ll) data[rs];
		return x * (r - l + 1);
	}

	ll add(int L, int R, ll x) {
		return add(1, 1, n, L, R, x);
	}

	ll query(int k, int l, int r, int L, int R) {
		ll res = 0;
		if (l >= L && r <= R)
			return res = data[k];
		if (l > R || r < L)
			return 0;
		Def
		pass(k, l, r);
		if (l <= mid)
			res += query(Ls, L, R);
		if (r > mid)
			res += query(Rs, L, R);
		return res;
	}

	ll query(int L, int R) {
		return query(1, 1, n, L, R);
	}
}sgt;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		sgt.modify(i, x);
	}
	for (int i = 1; i <= m; i++) {
		int kk, x, y, k;
		scanf("%d%d%d", &kk, &x, &y);
		if (kk == 1) {
			scanf("%d", &k);
			sgt.add(x, y, k);
		} else {
			printf("%lld\n", sgt.query(x, y));
			
		}
	}
	return 0;
}


