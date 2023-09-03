#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3000 + 10, M = 5000 + 10;
const long long Mod = 1e9 + 7;
ll read() {
	ll x = 0, f = 1;
	char c;
	while(!isdigit(c = getchar())) if(c == '-') f = -f;
	do{
		x = x * 10 + c - '0';
	}while(isdigit(c = getchar()));
	return x * f;
}
struct Edge{
	int to, nxt, from;
}edgedot[M * 2], edgeg[M * 2];
int low[N], stk[N], dfn[N], siz[N], bel[N], sizeg, top, sum, tim;
int hd[N], hg[N], cntd, cntg;
int n, m;
ll dp[N][M], ans;
ll fst_pow(int x, int s) {
	ll xx = x;
	ll ret = 1;
	while(s) {
		if(s & 1) ret = ret * xx % Mod;
		xx = xx * xx % Mod;
		s >>= 1;
	}
	return ret;
}
void dfs1(int t, int f) {
	dfn[t] = ++tim;
	low[t] = tim;
	stk[++top] = t;
	for(int i = hd[t]; i; i = edgedot[i].nxt) {
		int v = edgedot[i].to;
		if(v == f) continue;
		if(low[v] != 0) {
			low[t] = min(low[t], low[v]);
			continue;
		}
		dfs1(v, t);
		low[t] = min(low[t], low[v]);
	}
	if(low[t] == dfn[t]) {
		++sum;
		while(stk[top] != t) {
			++siz[sum];
			bel[stk[top]] = sum;
			--top;
		}
		++siz[sum];
		bel[stk[top]] = sum;
		--top;
	}
}
void dfs2(int t, int f) {
	ll bas = fst_pow(2, siz[t]) % Mod;
	dp[t][0] = 1;
	for(int i = hg[t]; i; i = edgeg[i].nxt) {
		int v = edgeg[i].to;
		if(v == f) continue;
		dfs2(v, t);
		for(int i = 1; i < sum; ++i) {
			for(int j = 1; j <= i; ++j) {
				dp[t][i] += dp[t][i - j] * dp[v][j - 1] % Mod;
				dp[t][i] %= Mod;
			}
		}
	}
	for(int i = 0; i < sum; ++i) {
		ans += dp[t][i] * (bas - 1) * fst_pow(2, sum - 1 - i);
		ans %= Mod;
	}
	dp[t][0] = dp[t][0] * (bas - 1);
	for(int i = 1; i < sum; ++i) {
		dp[t][i] = dp[t][i] * bas;
	}
//	cout << t << ' ' << ret << endl;
}
void addot(int from, int to) {
	edgedot[++cntd].to = to;
	edgedot[cntd].from = from;
	edgedot[cntd].nxt = hd[from];
	hd[from] = cntd;
}
void addg(int from, int to) {
	edgeg[++cntg].to = to;
	edgeg[cntg].nxt = hg[from];
	hg[from] = cntg;
}
int main() {
//  freopen("barrack.in", "r", stdin);
//  freopen("barrack.out", "w", stdout);
  n = read();
  m = read();
//  cout << n << ' ' << m << endl;
  for(int i = 1; i <= m; ++i) {
  	int u, v;
  	u = read(); v = read();
  	addot(u, v);
  	addot(v, u);
	}
	dfs1(1, 0);
	for(int i = 1; i < cntd; i += 2) {
		int u = edgedot[i].from, v = edgedot[i].to;
		if(bel[u] == bel[v]) ++sizeg;
		else {
			addg(bel[u], bel[v]);
			addg(bel[v], bel[u]);
		}
//		if(u == 4 or v == 4) cout << u << ' ' << v << endl;
	}
	dfs2(1, 0);
//	for(int i = 1; i <= sum; ++i) {
//		for(int j = 0; j < sum; ++j) {
//			ans += dp[i][j] * fst_pow(2, sum - 1 - j) % Mod;
//			ans %= Mod;
//		}
//	}
//	cout << low[4] << endl;
//	cout << sum << endl;
	printf("%lld", ans * fst_pow(2, sizeg) % Mod);
  return 0;
}

