#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5, M = 1e6 + 5;
const ll mod = 1e9 + 7;
int x[M], y[M], n, m, cnt = 0;
ll mpw[M], ans, awa[M], sz[N];
struct node {
	ll szx, szy;
	bool operator < (const node &x) const {
		return szy < x.szy;
	}
} pp[M];
bool vis[N];
vector<int> g[N];
void dfs(int u) {
	vis[u] = true; ++ cnt;
	for(int i = 0; i < g[u].size(); i ++) {
		int v = g[u][i];
		if(vis[v]) continue;
		dfs(v);
	}
}
void Dfs(int u, int fa) {
	sz[u] = 1;
	for(int i = 0; i < g[u].size(); i ++) {
		int v = g[u][i];
		if(v == fa) continue;
		Dfs(v, u);
		sz[u] += sz[v];
	}
}
int main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	scanf("%d%d", &n, &m); mpw[0] = 1;
	for(int i = 1; i <= max(n, m); i ++) 
		mpw[i] = mpw[i - 1] * 2 % mod;
	for(int i = 1; i <= m; i ++) scanf("%d%d", &x[i], &y[i]);
	ans = (mpw[n] - 1 + mod) % mod;
	if(m == n - 1) {
		for(int i = 1; i <= m; i ++) {
			g[x[i]].push_back(y[i]);
			g[y[i]].push_back(x[i]);
		}
		Dfs(1, 0);
		for(int i = 2; i <= n; i ++) {
			pp[i].szx = sz[i]; pp[i].szy = n - sz[i];
			if(pp[i].szx > pp[i].szy) swap(pp[i].szx, pp[i].szy);
		}
		sort(pp + 2, pp + 1 + n);
		for(int i = 2; i <= n; i ++)
			ans += ((mpw[pp[i].szx] - 1 + mod) % mod + (mpw[pp[i].szy] - 1 + mod) % mod) % mod * mpw[m - i + 1],
			ans %= mod;
		cout << ans << '\n';
		return 0;
	}
	for(int i = 1; i <= m; i ++) {
		for(int j = 1; j <= n; j ++) 
			g[j].clear(), vis[j] = false;
		for(int j = 1; j <= m; j ++)
			if(i != j) {
				g[x[j]].push_back(y[j]);
				g[y[j]].push_back(x[j]);
			}
		for(int j = 1; j <= n; j ++)
			if(!vis[j]) {
				cnt = 0;
				dfs(j);
				awa[i] += (mpw[cnt] - 1 + mod) % mod;
				awa[i] %= mod;
			}
	}
	sort(awa + 1, awa + 1 + m);
	for(int i = 1; i <= m; i ++)
		ans += awa[i] * mpw[m - i] % mod, ans %= mod;
	cout << ans << '\n';
	return 0;
}
