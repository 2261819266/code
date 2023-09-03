#include <bits/stdc++.h>

#define fo(x) freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout);
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

const int maxn = 3e2 + 5;
const int maxk = 2 * maxn + 5;
const int maxm = 2e6 + 5;

int T;
int n, m, k, a[maxm], ct[maxk], ps[maxk], s[maxn], t[maxn];

deque<int> S[maxn];

struct Opt {
	int o, x, y;
};
vector<Opt> A;

void solve() {
	rd(n), rd(m), rd(k); A.clear();
	fill(ct + 1, ct + k + 1, 0);
	fill(ps + 1, ps + k + 1, 0);
	rep (i, 1, m) {
		rd(a[i]), ct[a[i]] += 1;
		s[i] = ps[a[i]];
		if (ps[a[i]]) t[ps[a[i]]] = i;
		ps[a[i]] = i;
	}
	if (n == 1) {
		rep (i, 1, m) A.push_back({1, 1, 0});
		return;
	}
	if (k == 2 * n - 2) {
		rep (i, 1, m) {
			int u = a[i];
			int p = (u + 1) / 2;
			if (S[p].empty()) A.push_back({1, p, 0}), S[p].push_back(u);
			else if (S[p].back() == u) A.push_back({1, p, 0}), S[p].pop_back();
			else if (S[p].front() == u) A.push_back({1, n, 0}), A.push_back({2, p, n}), S[p].pop_front();
			else A.push_back({1, p, 0}), S[p].push_back(u);
		}
		return;
	}
	rep (i, 1, m) {
		int u = a[i];
		if (S[1].empty() && S[2].empty()) {
			S[1].push_back(u), A.push_back({1, 1, 0});
			continue;
		}
		bool f = false;
		rep (j, 1, 2) {
			if (S[j].empty()) continue;
			if (S[j].back() == u) A.push_back({1, j, 0}), S[j].pop_back(), f = true;
			else if (S[j].front() == u) A.push_back({1, 3 - j, 0}), A.push_back({2, j, 2 - j}), S[j].pop_front(), f = true;
		} 
		if (f) continue;
		int p = 1;
		if (a[i + 1] != u) {
			if (!S[1].empty() && (S[1].front() == u || S[1].back() == u)) p = 2;
		}
		A.push_back({1, p, 0}), S[p].push_back(u);
	}
}

/*

1
2 10 3
1 2 3 2 1 3 2 1 2 1*/

bool Ed;

int main() {
	fo(meow)
	cerr << (double)std::abs(&Ed - &St) / 1024.0 / 1024.0 << "Mb\n";
	rd(T);
	rep (i, 1, T) {
		if (i > 1) putchar('\n');
		solve();
		printf("%d", (int)A.size());
		rep (j, 0, (int)A.size() - 1) {
			Opt &x = A[j];
			if (x.o == 1) printf("\n%d %d", x.o, x.x);
			if (x.o == 2) printf("\n%d %d %d", x.o, x.x, x.y);
		}
	}
	cerr << "\n" << double(clock()) / CLOCKS_PER_SEC << "s\n";
	return 0;
}

