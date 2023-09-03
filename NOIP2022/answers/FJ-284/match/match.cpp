#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define U(i,b,e) for(int i(b),END##i(e);i<=END##i;++i)
#define D(i,e,b) for(int i(e),END##i(b);i>=END##i;--i)

const int N = 3005;
int T, n, a[N], b[N];
ull f[N][N];

int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	
	scanf("%d%d", &T, &n);
	U (i, 1, n) scanf("%d", a + i);
	U (i, 1, n) scanf("%d", b + i);
	U (i, 1, n) {
		int mA = -1, mB = -1;
		U (j, i, n) {
			mA = max(mA, a[j]);
			mB = max(mB, b[j]);
			f[i][j] = f[i][j - 1] + ull(mA) * mB;
		}
	}
	int Q; scanf("%d", &Q);
	while (Q--) {
		int l, r; scanf("%d%d", &l, &r);
		ull ans = 0;
		U (i, l, r) ans += f[i][r];
		printf("%llu\n", ans);
	}
	return 0;
}

// du cuo ti le
// wo shi **
//const int N = 250005;
//int T, n, Q;
//pair<int, int> qr[N];
//
//// rect add, rect sum
//struct Op { int x1, x2, y, v, id; };
//bool operator < (const Op &l, const Op &r) {
//	return (l.y == r.y) ? l.id < r.id : l.y < r.y; }
//vector<Op> vec;
//
//void insert(int x1, int x2, int y1, int y2, int val, int id) {
//	if (id) {
//		vec.push_back({x1, x2, y1 - 1, -1, id});
//		vec.push_back({x1, x2, y2, 1, id});
//	} else {
//		vec.push_back({x1, x2, y1, val, 0});
//		vec.push_back({x1, x2, y2 + 1, -val, 0});
//	}
//}
//
//struct DT {
//	int *v, ls[N], rs[N], lb[N], rb[N], root;
//	void build(int *v_) { v = v_;
//		int stk[N] {}, sp = 0;
//		U (i, 1, n) { int t = sp;
//			while (sp && v[stk[sp]] < v[i]) --sp;
//			if (sp != t)
//				ls[i] = stk[sp + 1];
//			rs[stk[sp]] = i;
//			stk[++sp] = i;
//		}
//		root = stk[1];
//	}
//	void dfs(int u) {
//		lb[u] = rb[u] = u;
//		if (ls[u]) { dfs(ls[u]), lb[u] = lb[ls[u]]; }
//		if (rs[u]) { dfs(rs[u]), rb[u] = rb[rs[u]]; }
//		insert(lb[u], u, u, rb[u], v[u], 0);
//	}
//	ull bf(int u, int b, int e) {
//		if (!u) return 0;
//		if (e < u) return bf(ls[u], b, e);
//		if (b > u) return bf(rs[u], b, e);
//		ull ans = 1ull * v[u] * (u - max(lb[u], b) + 1) * 
//			(min(rb[u], e) - u + 1);
//		ans += bf(ls[u], b, e);
//		ans += bf(rs[u], b, e);
//		return ans;
//	}
//} dA, dB;
//
//struct ST { // range sum, range query
//	ull tr[N << 2] {}, tag[N << 2] {};
//	#define mid ((l + r) >> 1)
//	#define LS (p << 1)
//	#define RS (LS | 1)
//	void pushdown(int p, int l, int r) {
//		tr[LS] += tag[p] * (mid - l + 1);
//		tr[RS] += tag[p] * (r - mid);
//		tag[p] = 0;
//	}
//	void add(int b, int e, ull v, int p = 1, int l = 1, int r = n) {
//		if (b <= l && e >= r) {
//			tag[p] += v;
//			tr[p] += v * (r - l + 1);
//			return;
//		}
//		pushdown(p, l, r);
//		if (b <= mid) add(b, e, v, LS, l, mid);
//		if (e > mid) add(b, e, v, RS, mid + 1, r);
//		tr[p] = tr[LS] + tr[RS];
//	}
//	ull query(int b, int e, int p = 1, int l = 1, int r = n) {
//		if (b <= l && e >= r) return tr[p];
//		ull v = 0; pushdown(p, l, r);
//		if (b <= mid) v = query(b, e, LS, l, mid);
//		if (e > mid) v += query(b, e, RS, mid + 1, r);
//		return v;
//	}
//};
//
//void proc(DT &dt, ull* ans) {
//	vector<Op>().swap(vec);
//	dt.dfs(dt.root);
//	U (i, 1, Q)
//		insert(qr[i].first, qr[i].second, qr[i].first, qr[i].second,
//			0, i);
//	sort(vec.begin(), vec.end());
//	int laY = vec[0].y;
//	for (size_t i = 0; i != vec.size(); ++i) {
//		// history version sum
//		// matrix segtree
//		// can't write
//	}
//}
//
//void brute(DT &dt, ull* ans) {
//	U (i, 1, Q) {
//		ans[i] = dt.bf(dt.root, qr[i].first, qr[i].second);
//	}
//}
//
//int main() {
//	freopen("match2.in", "r", stdin);
//	
//	int a[N], b[N];
//	scanf("%d%d", &T, &n);
//	U (i, 1, n) scanf("%d", a + i);
//	U (i, 1, n) scanf("%d", b + i);
//	dA.build(a);
//	dB.build(b);
//	scanf("%d", &Q);
//	U (i, 1, Q) {
//		int l, r; scanf("%d%d", &l, &r);
//		qr[i] = {l, r};
//	}
//	
//	ull mA[N] {}, mB[N] {};
//	brute(dA, mA);
//	brute(dB, mB);
//	U (i, 1, Q)
//		printf("%llu\n", mA[i] * mB[i]);
//}