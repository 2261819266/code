#include <cstdio>
#define ll long long

const int maxn = 1e5 + 5;

struct node {
	ll sum, lazy, n;
	operator int() { return sum + lazy * n; }
	node &operator=(ll x) { return *this = (node){x}; }
	node &operator+=(ll x) { return *this = *this + x; }
};

struct SegTree {
#define ls	(k << 1)
#define rs	(ls | 1)
#define Def	int mid = (l + r) / 2;
#define Ls	ls, l, mid
#define Rs	rs, mid + 1, r
	node data[maxn << 2];

	ll modify(int k, int l, int r, int i, ll x) {
		ll res;
		if (l == r) {
			res = data[k];
			data[k] = x;
			return res;
		}
		Def
		if (i <= mid)
			res = modify(Ls, i, x);
		else
			res = modify(Rs, i, x);
		data[k] = (int) data[ls] + (int) data[rs];
		return res;
	}

	void pass(int k, int l, int r) {
		Def
		int k1 = mid - l + 1;
		int k2 = r - mid;
		data[ls].lazy += data[k].lazy;
		data[rs].lazy += data[k].lazy;
		data[ls].n = k1;
		data[rs].n = k2;
		// data[ls] += k1 * data[k].lazy;
		// data[rs] += k2 * data[k].lazy;
		data[k].n = 0;
	}
#define pass(k) pass(k, l, r)

	ll query(int k, int l, int r, int L, int R) {
		if (r < L || R < l)
			return 0ll;
		if (l >= L && r <= R)
			return data[k];
		Def
		pass(k);
		return query(Ls, L, R) + query(Rs, L, R);
	}

	int modify(int k, int l, int r, int L, int R, ll x){
		ll res;
		if (l == r) {
			if (l >= L && l <= R) {
				res = data[k];
				data[k] += x;
			}
			return res;
		}
		if (l >= L && r <= R)
			return res = data[k].lazy += x, data[k].n = r - l + 1;
		Def
		if (l <= mid)
			res += modify(Ls, L, R, x);
		if (r > mid)
			res += modify(Rs, L, R, x);
		data[k] = (int) data[ls] + (int) data[rs];
		return res;
	}
} sgt;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		sgt.modify(1, 1, n, i, x);
	}
	// for (int i = 1; i <= 16; i++) {
	// 	printf("data[%d] = %lld \n", i, (int) sgt.data[i]);
	// }
	for(int i = 1; i <= m; i++){
		ll kk, x, y, k;
		scanf("%lld%lld%lld", &kk, &x, &y);
		if (kk == 1) {
			scanf("%d", &k);
			sgt.modify(1, 1, n, x, y, k);
			// for (int j = 1; j < 16; j++) {
			// 	printf("data[%d] = %d\n", j, (int) sgt.data[j]);
			// }
			// puts("");
		} else {
			printf("%lld\n", sgt.query(1, 1, n, x, y));
		}
	}
	return 0;
}

