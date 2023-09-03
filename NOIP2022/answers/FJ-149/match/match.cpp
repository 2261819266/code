#include <bits/stdc++.h>

// #define fo(x) freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout);
#define rep(i, l, r) for (int i = l, rep##i = r; i <= rep##i; ++i)
#define per(i, r, l) for (int i = r, per##i = l; i >= per##i; --i)

using namespace std; typedef long long ll; typedef unsigned long long ull;
bool St;
namespace IO {
const int max_io_buf = 1 << 17;
char I[max_io_buf], *p1, *p2;
inline char gc() {
	return p1 == p2 && (p2 = (p1 = I) + fread(I, 1, sizeof(I), stdin), p2 == p1) ? EOF : *p1++;
} 
//inline char gc() {
//	return (char)getchar();
//}
} 

template <typename T> void rd(T &x) {
	x = 0; char c = IO::gc(); bool f = false;
	while (!isdigit(c)) f |= (c == '-'), c = IO::gc();
	while (isdigit(c)) x = x * 10 + c - '0', c = IO::gc();
	if (f) x *= -1;
}

const int maxn = 2.5e5 + 5;
const int maxlgn = 20;

int typ, n, q;
int a[maxn], b[maxn];
int pw[maxn], lg[maxn];
 
int S[maxn];

struct Tr {
	int *a; int L[maxn], R[maxn], rt;
	int s[maxlgn][maxn];
	map<int, ull> M[maxn];
	void build(int *t) {
		a = t;
		*S = 0; S[1] = 0; rt = 0;
		rep (i, 1, n) {
			while (*S && a[S[*S]] < a[i]) --*S;
			if (*S) L[i] = R[S[*S]], R[S[*S]] = i;
			else rt = i, L[i] = S[1];
			S[++*S] = i;
		}
		rep (i, 1, n) s[0][i] = a[i];
		rep (i, 1, lg[n]) rep (j, 1, n - pw[i] + 1)
			s[i][j] = max(s[i - 1][j], s[i - 1][j + pw[i - 1]]);
//		rep (i, 1, n) {
//			assert(a[L[i]] <= a[i] && a[R[i]] <= a[i]);
//		}
	}
	ull ask(int l, int r) {
		int k = lg[r - l + 1];
		return max(s[k][l], s[k][r - pw[k] + 1]);
	}

	void jmp(int &u, int l, int r) {
		while (!(l <= u && u <= r)) {
			if (u < l) u = R[u];
			else u = L[u];
		}
	}
	ull solve(int u, int l, int r) {
		if (!u || l > r) return 0;
		if (l == r) return a[l];
		if (M[l].count(r)) return M[l][r];
		jmp(u, l, r);
		ull A = ull(u - l + 1) * ull(r - u + 1) * a[u];
//		if (l == 1 && r == 1) cerr << A << "::";
		A += solve(L[u], l, u - 1);
		A += solve(R[u], u + 1, r);
		return M[l][r] = A;
	}
} ta, tb;

ull bm(int l, int r) {
	ull A = 0;
	rep (i, l, r) rep (j, i, r)
		A += ta.ask(i, j) * tb.ask(i, j);
	return A;
}

//ull solveR(Tr *x, int u, int l, int r) {
//	if (!u || l > r) return 0;
//	if (l == r) return x->a[l];
//	jmp(*x, u, l, r);
//	ull A = 0;
//	while (u && l <= r) {
//		A += ull(r - u + 1) * x->a[u];
//		r = u - 1, u = x->L[u];
//	}
//	return A;
//}
//ull solveL(Tr *x, int u, int l, int r) {
//	if (!u || l > r) return 0;
//	if (l == r) return x->a[l];
//	jmp(*x, u, l, r);
//	ull A = 0;
//	while (u && l <= r) {
//		A += ull(u - l + 1) * x->a[u];
//		l = u + 1, u = x->R[u];
//	}
//	return A;
//}

map<int, ull> M[maxn];

//ull A;
ull solve(Tr *x, Tr *y, int u, int v, int l, int r) {
	ull A = 0;
	if (!u || !v || l > r) return 0;
	if (l == r) return x->a[l] * y->a[l];
	if (M[l].count(r)) return M[l][r];
	x->jmp(u, l, r), y->jmp(v, l, r);
	if (u == v) {
		ull o = ull(u - l + 1) * ull(r - v + 1);
		A += o * x->a[u] * y->a[v];
		A += solve(x, y, u, v, l, u - 1);
		A += solve(x, y, u, v, v + 1, r);
		return M[l][r] = A;
	}
	if (u > v) swap(x, y), swap(u, v);
//	cerr << u << " " << v << endl;
	ull o = ull(u - l + 1) * ull(r - v + 1);
	A += o * x->a[u] * y->a[v];
//	cerr << A << endl;
	o = y->solve(v, l, v - 1) - y->solve(v, l, u - 1) - y->solve(v, u + 1, v - 1);
	A += o * x->a[u];
//	cerr << y->solve(v, l, v - 1) << " " << y->solve(v, l, u - 1) << " " << y->solve(v, u + 1, v - 1) << endl;
	o = x->solve(u, u + 1, r) - x->solve(u, u + 1, v - 1) - x->solve(u, v + 1, r);
	A += o * y->a[v];
//	cerr << A << endl;

	A += solve(x, y, u, v, l, u - 1);
	A += solve(x, y, u, v, v + 1, r);
	A += solve(x, y, u, v, u + 1, v - 1);
//	cerr << l << " " << r << " :" << A << " []" << bm(l, r) << endl;

	return M[l][r] = A;
}

bool Ed;

int main() {
	// fo(match)
	cerr << (double)std::abs(&Ed - &St) / 1024.0 / 1024.0 << "Mb\n";
	rd(typ), rd(n);
	lg[0] = lg[1] = 0, pw[0] = 1, pw[1] = 2;
	rep (i, 2, n) lg[i] = lg[i / 2] + 1, pw[i] = pw[i - 1] * 2;

	rep (i, 1, n) rd(a[i]);
	rep (i, 1, n) rd(b[i]);
	ta.build(a), tb.build(b);
//	cerr << "qwq";
	rd(q);
	rep (i, 1, q) {
		int l, r; rd(l), rd(r);
		if (typ <= 2) {
			printf("%llu\n", bm(l, r));
			continue;
		}
//		A = 0;
		ull A = solve(&ta, &tb, ta.rt, tb.rt, l, r);
		printf("%llu\n", A);
//		cerr << A << " " << bm(l, r) << endl;
//		cerr << A << endl;
//		cerr << i;
	}
	
	cerr << "\n" << double(clock()) / CLOCKS_PER_SEC << "s\n";
	return 0;
}

/*
3 4
1 3 2 4
1 4 2 3
1
1 4
*/

