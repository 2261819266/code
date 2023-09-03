#include <cstdio>
#include <cstring>
#include <algorithm>
#define f(x, y, z) for (auto x = y, __ = z; x < __; ++x)
#define ll long long
#define mid (l + r) / 2

const int maxn = 1e6 + 8;
int root[maxn], cnt = 1;
ll a[maxn << 5];
int ls[maxn << 5], rs[maxn << 5];

int build(int k, int l, int r, int i, ll x) {
	if (l == r) return a[k] = x;
	if (i <= mid) {
		if (!ls[k]) ls[k] = ++cnt;
		build(ls[k], l, mid, i, x);
	} else {
		if (!rs[k]) rs[k] = ++cnt;
		build(rs[k], mid + 1, r, i, x);
	}
	return a[k] = a[ls[k]] + a[rs[k]];
}

int modify(int pre, int l, int r, int i, ll x) {
	int p = ++cnt;
	a[p] = a[pre], ls[p] = ls[pre], rs[p] = rs[pre];
	if (l == r) {
		a[p] = x;
		return p;
	}
	if (i <= mid) 
		ls[p] = modify(ls[pre], l, mid, i, x);
	else 
		rs[p] = modify(rs[pre], mid + 1, r, i, x);
	a[p] = a[ls[p]] + a[rs[p]];
	return p;
}

ll ask(int p, int l, int r, int i) {
	if (l == r) return a[p];
	return i <= mid ? ask(ls[p], l, mid, i) : ask(rs[p], mid + 1, r, i);
}

int main() {
#ifdef LOCAL
	LOCALfo
#endif
	int n;
	int m;
	root[0] = 1;
	scanf("%d%d", &n, &m);
	f(i, 1, n + 1) {
		int x;
		scanf("%d", &x);
		build(1, 1, n, i, x);
	}
	f(i, 1, m + 1) {
		int v, op, id;
		ll x;
		scanf("%d%d%d", &v, &op, &id);
		if (op == 1) {
			scanf("%lld", &x);
			root[i] = modify(root[v], 1, n, id, x);
		} else root[i] = root[v], printf("%lld\n", ask(root[v], 1, n, id));
	}
}