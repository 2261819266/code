#include <cstdio>
#include <cmath>
#include <algorithm>
#define ll long long

const int maxn = 2e5 + 8, maxm = 1e3 + 8;
struct node {
#define nn (r - l + 1)
	ll a[maxm] = {}, sum, lazy;
	int l, r;

	operator ll() { return sum; }

	ll &operator[](int x) { return a[x]; }
	
	node operator+=(ll x) { lazy += x; return *this; }

	void pass() {
		if (!lazy) return;
		for (int i = 0; i < nn; i++) {
			a[i] += lazy;
		}
		sum += nn * lazy;
		lazy = 0;
	}
	
	ll add(int L, int R, ll x) {
		if (l >= L && r <= R) return lazy += x;
		ll ans = 0;
		for (int i = std::max(l, L); i <= std::min(r, R); i++) {
			a[i % nn] += x;
			sum += x;
		}
		return ans;
	}

	ll query(int L, int R) {
		if (l >= L && r <= R) return sum + lazy * nn;
		ll ans = 0;
		for (int i = std::max(l, L); i <= std::min(r, R); i++) {
			ans += a[i % nn];
		}
		return ans;
	}
};

struct Tree {
#define Def int k1 = L / sn, k2 = L % sn, k3 = R / sn, k4 = R % sn;
	node a[maxm];
	int n, sn;

	void init(int x) {
		n = x;
		sn = sqrt(n);
		for(int i = 0; i < n / sn + 1;) {
			a[i].l = i * sn;
			i++;
			a[i - 1].r = i * sn - 1;
		}
	}

	void modify(int i, ll x) {
		a[i / sn][i % sn] = x;
		a[i / sn].sum += x;
	}

	void add(int L, int R, int x) {
		for (int i = 0; i < n / sn + 1; i++) {
			a[i].add(L, R, x);
		}
	}
	
	ll query(int L, int R) {
		ll res = 0;
		for (int i = 0; i < n / sn + 1; i++) {
			a[i].pass();
			res += a[i].query(L, R);
		}
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
	sgt.init(n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		sgt.modify(i, x); 
	}
	for (int i = 0; i < m; i++) {
		int kk, x, y, k;
		scanf("%d%d%d", &kk, &x, &y);
		if(kk == 1){
			scanf("%d", &k);
			sgt.add(x - 1, y - 1, k);
		} else 
			printf("%lld\n", sgt.query(x - 1, y - 1));
	}
	return 0;
}

