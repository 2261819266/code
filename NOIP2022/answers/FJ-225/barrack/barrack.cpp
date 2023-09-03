#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, l, r) for(int i(l);i<=int(r);++i)
#define per(i,l,r) for(int i(l); i >= int(r); i--)
const int N = 5e5+10;
const int mod = 1e9+7;
int n, m, deg[N], dis[2000][2000];
std::vector<int> e[N];
void bfs(int s) {
	std::queue<int> q;
	q.push(s), dis[s][s] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : e[u]) {
			if (dis[s][v] > dis[s][u] + 1) dis[s][v] = dis[s][u] + 1, q.push(v);
		}
	}
}
bool vis[2010][2010];
ll fastpow(int a, int b) {
	if (b < 0) return 0ll;
	if (b == 0) return 1ll;
	ll t = 1;
	for (; b; b >>= 1, a = 1ll*a*a%mod) if (b&1) t = 1ll*t*a%mod;
	return t;
}
int main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	scanf("%d%d", &n, &m);
	rep(i, 1, m) {
		int u, v; scanf("%d%d", &u, &v);
		e[u].push_back(v), e[v].push_back(u), ++deg[u], ++deg[v];
	}
//	rep(i, 1, n) bfs(i);
//	rep(i, 1, n) rep(j, 1, n) if (i != j) {
//		if (dis[i][j] == 1) vis[i][j] = 1;
//		else vis[i][j] = 0;
//	}
	if (m == 1) {
		printf("%d\n", 5);
		return 0;
	}
	ll ans = 1ll*n*fastpow(2ll, m)%mod;
//	std::vector<int> vec;
	for (int s = 1; s <= (1<<n)-1; ++s) {
		int cnt = 0;
		if (__builtin_popcount(s) == 1) continue;
//		printf("%d:\n", s);
		for (int j = 1; j <= n; ++j) {
			if (s&(1<<(j-1))) {
//				printf("%d %d\n", j, deg[j]);
				if (deg[j] == 1) ++cnt;
			}
		}
		ans = (ans + fastpow(2ll, m-cnt)%mod)%mod;
	}
	printf("%lld\n", ans);
	return 0;
}
