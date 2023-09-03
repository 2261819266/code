#include <bits/stdc++.h>
typedef unsigned long long LL;
const LL SZ = 250010;
LL read() {
	char ch;
	LL res = 0;
	while (!isdigit(ch = getchar()));
	do {
		res = res * 10 + ch - '0';
	} while (isdigit(ch = getchar()));
	return res;
}
LL T, n, a[SZ], b[SZ], Q;
struct SegmentTree {
	LL tr[SZ << 4];
	SegmentTree() {
		memset(tr, 0, sizeof tr);
	}
	LL ls(LL x) {
		return x << 1;
	}
	LL rs(LL x) {
		return ls(x) + 1;
	}
	LL mid(LL x, LL y) {
		return (x + y) >> 1;
	}
	void pushUp(LL p) {
		tr[p] = std::max(tr[ls(p)], tr[rs(p)]);
	}
	void build(LL *x, LL l, LL r, LL p) {
		if (l == r) {
			tr[p] = x[l];
			return;
		}
		LL m = mid(l, r);
		build(x, l, m, ls(p));
		build(x, m + 1, r, rs(p));
		pushUp(p);
	}
	LL query(LL l, LL r, LL curL, LL curR, LL p) {
		if (l <= curL && curR <= r) {
			return tr[p];
		}
		LL m = mid(curL, curR), ans = 0;
		if (m >= l) ans = std::max(ans, query(l, r, curL, m, ls(p)));
		if (m < r) ans = std::max(ans, query(l, r, m + 1, curR, rs(p)));
		return ans;
	}
	void build(LL *x, LL size) {
		build(x, 1, size, 1);
	}
	LL query(LL l, LL r) {
		return query(l, r, 1, n, 1);
	}
} tA, tB;
//LL lI[SZ], rI[SZ], pre[SZ], lMin = INT_MAX, rMax = 0;
int main() {
//	freopen("match1.in", "r", stdin);
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	T = read(), n = read();
	for (LL i = 1; i <= n; ++i) a[i] = read();
	for (LL i = 1; i <= n; ++i) b[i] = read();
	tA.build(a, n);
	tB.build(b, n);
	std::cin >> Q;
	LL lI, rI;
	for (LL i = 1; i <= Q; ++i) {
		LL ans = 0;
		lI = read(), rI = read();
//		std::cin >> lI[i] >> rI[i];
//		lMin = std::min(lMin, lI[i]);
//		rMax = std::max(rMax, rI[i]);
		for (LL p = rI; p >= lI; --p) {
			for (LL q = p; q <= rI; ++q) {
				ans += tA.query(p, q) * tB.query(p, q);
			}
		}
		printf("%llu\n", ans);
	}
	return 0;
}
