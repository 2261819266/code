#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7, M = 1e6 + 7, Mod = 1e9 + 7;
inline int Add(int x, int y) { return (x += y) >= Mod ? x - Mod : x; }
inline int Add(int x, int y, int z) { return Add(Add(x, y), z); }
inline void Inc(int &x, int y) { if((x += y) >= Mod) x -= Mod; }
inline int Sub(int x, int y) { return (x -= y) < 0 ? x + Mod : x; }
inline int Mul(int x, int y) { return (long long)x * y % Mod; }
int n, m, u, v, dp[N], val[N], pt[N], et[N], pow2[N + M], ans;
int dfn[N], dft, low[N], stk[N], tp, bcc[N], bt;
vector<int> G[N], T[N];
void tarjan(int x, int f = -1) {
	dfn[x] = low[x] = ++dft, stk[++tp] = x;
	for(int i: G[x]) if(i != f) {
		if(dfn[i]) low[x] = min(low[x], dfn[i]);
		else tarjan(i, x), low[x] = min(low[x], low[i]);
	}
	if(dfn[x] == low[x])
		for(bcc[stk[tp]] = ++bt;;) {
			if(stk[tp--] == x) break;
			else bcc[stk[tp]] = bt;
		}
}
void Dfs1(int x, int f = -1) {
	val[x] = et[x];
	for(int i: T[x]) if(i != f)
		Dfs1(i, x), val[x] += 1 + val[i];
}
void Dfs2(int x, int f = -1) {
	int dp0 = 1, dp1 = 0, dp2 = 0, p, q, r;
	for(int i: T[x]) if(i != f) {
		Dfs2(i, x), p = dp0, q = dp1, r = dp2;
		dp0 = Mul(p, pow2[val[i] + 1]);
		dp1 = Add(Mul(p, dp[i]), Mul(q, pow2[val[i] + 1]));
		dp2 = Add(Mul(Add(q, r), dp[i]), Mul(r, pow2[val[i] + 1]));
	}
	int w1 = Mul(Sub(pow2[pt[x]], 1), pow2[et[x]]), w2 = pow2[pt[x] + et[x]];
	dp[x] = Add(Mul(dp0, w1), Mul(Add(dp1, dp2), w2));
	Inc(ans, Mul(Add(Mul(Add(dp0, dp1), w1), Mul(dp2, w2)), pow2[val[1] - val[x]]));
}
int main() {
	freopen("barrack.in", "r", stdin), freopen("barrack.out", "w", stdout);
	scanf("%d %d", &n, &m), pow2[0] = 1;
	for(int i = 1; i <= n + m; ++i) pow2[i] = Add(pow2[i - 1], pow2[i - 1]);
	for(int i = 1; i <= m; ++i)
		scanf("%d %d", &u, &v),
		G[u].push_back(v), G[v].push_back(u);
	tarjan(1);
	for(int i = 1; i <= n; ++i) ++pt[bcc[i]];
	for(int i = 1; i <= n; ++i) for(int j: G[i])
		if(bcc[i] == bcc[j]) et[bcc[i]] += (i < j);
		else T[bcc[i]].push_back(bcc[j]);
	Dfs1(1), Dfs2(1), printf("%d", ans);
	return 0;
}
