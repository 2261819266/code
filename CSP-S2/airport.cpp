#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>

// #define fo(x) freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout);

const int maxn = 1e5 + 6;

struct Node {
	int a, b;
	bool operator<(const Node& r) const {
		return a < r.a;
	}
};

int n, m[2];
Node s[2][maxn];
int f[2][maxn], h[2][maxn];
int fr[2][maxn], to[2][maxn];
//int ne[2][maxn];
bool vis[2][maxn];
//std::set<std::pair<int, int> > S[2];
int g[2][maxn], gtot[2];

int q[maxn];

struct SegTree {
#define ls (k << 1)
#define rs (ls | 1)
#define Def int mid = (l + r) / 2;
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
	int t[maxn << 2], mn[maxn << 2];
	void pushup(int K, int k) {
		// mn[k] = std::min(mn[ls], mn[rs]);
		mn[k] = s[K][mn[ls]].b < s[K][mn[rs]].b ? mn[ls] : mn[rs];
	}
	int modify(int K, int k, int l, int r, int x) {
		int res;
		if (l == r) {
			res = mn[k];
			mn[k] = x;
			return res;
		}
		Def
		if (s[K][mn[ls]].b < s[K][x].a) 
			res = modify(K, Ls, x);
		else
			res = modify(K, Rs, x);
		pushup(K, k);
		return res;
	}
} sgt;

void solve() {
	int p;
	for (int k = 0; k < 2; ++k) {
		int cc = 0;
		memset(sgt.t, 0, sizeof(sgt.t));
		memset(sgt.mn, 0, sizeof(sgt.mn));
		for (int i = 1; i <= m[k]; ++i) {
			//std::set<std::pair<int, int> >::iterator iter = S[k].upper_bound(std::make_pair(-s[k][i].a, i));
			/*
			if (iter != S[k].end()) {
				p = iter->second;
				S[k].erase(iter);
			} else {
				p = 0;
			}*/
			p = sgt.modify(k, 1, 1, m[k], i);
			f[k][i] = f[k][p] + 1;
			to[k][i] = p;
			//printf("k=%d | %d -> %d\n", k, p, i);
			if (p) fr[k][p] = i;
			//S[k].insert(std::make_pair(-s[k][i].b, i));
		}
		for (int i = m[k]; i; --i) {
			if (!fr[k][i]) h[k][i] = f[k][i];
			if (to[k][i]) h[k][to[k][i]] = h[k][i];
		}
		for (int i = 1; i <= m[k]; ++i) {
			if (to[k][i] == 0) {
				g[k][gtot[k] + 1] = g[k][gtot[k]] + h[k][i];
				++gtot[k];
				//printf("g_%d[%d] %d\n", k, gtot[k], g[k][gtot[k]]);
			}
		}
		for (int i = gtot[k] + 1; i <= n; ++i)
			g[k][i] = g[k][i - 1];
	}
	int ans = 0;
	for (int i = 0; i <= n; ++i) 
		ans = std::max(ans, g[0][i] + g[1][n - i]);
	printf("%d", ans);
}

int main() {
	// fo(airport)
	LOCALfo
	scanf("%d%d%d", &n, &m[0], &m[1]);
	for (int k = 0; k < 2; ++k) {
		for (int i = 1; i <= m[k]; ++i)
			scanf("%d%d", &s[k][i].a, &s[k][i].b);
		std::sort(s[k] + 1, s[k] + m[k] + 1);
	}
	if (n >= m[0] + m[1]) {
		printf("%d", m[0] + m[1]);
		return 0;
	}
	solve();
	
	return 0;
} 