// Per aspera ad astra.
// 1004535809
#include <set>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define re register
#define ll long long
#define ull unsigned long long
using namespace std;
const int P = 1e9 + 7, oo = 0x3f3f3f3f, N = 5e5;
inline int Add(re int x, re int y) {return x + y < P ? x + y : x + y - P;}
inline int Sub(re int x, re int y) {return x - y < 0 ? x - y + P : x - y;}
inline int Mul(re int x, re int y) {re ull z = 1llu * x * y; return z < P ? z : z % P;}
struct E {
	int tot, Hd[N + 5], Pr[N + 5 << 2], Ver[N + 5 << 2];
	inline void Adde(re int u, re int v) {
		Pr[++tot] = Hd[u], Ver[tot] = v, Hd[u] = tot;
		Pr[++tot] = Hd[v], Ver[tot] = u, Hd[v] = tot;
	}
} G, T;
int clk, tp, bcc, Sz[N + 5], Stk[N + 5], Dfn[N + 5], Low[N + 5], Num[N + 5];
set<pair<int, int> > St;
inline void Dfs(re int u, re int fa) {
	Dfn[u] = Low[u] = ++clk; Stk[++tp] = u;
	for (re int i = G.Hd[u], v; i; i = G.Pr[i]) if (G.Ver[i] ^ fa) {
		v = G.Ver[i];
		if (!Dfn[v]) {
			Dfs(v, u); Low[u] = min(Low[u], Low[v]);
		}
		else if (!Num[v]) Low[u] = min(Low[u], Dfn[v]); 
	}
	if (Dfn[u] == Low[u]) {
		Sz[++bcc] = tp;
		while (Stk[tp + 1] ^ u) {
			Num[Stk[tp--]] = bcc;
		}
	}
}
int F[N + 5], FF[N + 5];
inline void DP(re int u, re int fa) {
	FF[0] = FF[1] = 1; re int tot = 1;
	for (re int i = T.Hd[u], v; i; i = T.Pr[i]) if (T.Ver[i] ^ fa) {
		v = T.Ver[i]; DP(v, u);
		for (re int x = 1; x <= tot; ++x) {
			F[u] = Add(F[u], Mul(F[v], FF[x]));
			FF[x + 1] = Add(FF[x], Mul(F[v], FF[x]));
		}
		++tot;
	}
}
signed main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	re int n, m;
	scanf("%d%d", &n, &m);
	for (re int i = 1, u, v; i <= m; ++i) {
		scanf("%d%d", &u, &v);
		G.Adde(u, v);
	}
	for (re int i = 1; i <= n; ++i) if (!Dfn[i]) Dfs(i, 0);
	for (re int i = 1; i <= n; ++i) {
		for (re int j = G.Hd[i]; j; j = G.Pr[j]) {
			if ((Num[i] ^ Num[G.Ver[j]]) && St.find(make_pair(Num[i], Num[G.Ver[j]])) != St.end() && St.count(make_pair(Num[G.Ver[j]], Num[i])) != St.end()) {
				St.insert(Num[i], Num[G.Ver[j]]); T.Adde(i, G.Ver[j]);
			}
		}
	}
	DP(1, 0);
	printf("%d\n", F[1]);
	return 392699 ^ 392699;
}
