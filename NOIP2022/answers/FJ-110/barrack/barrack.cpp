#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
const int N = 5e5 + 5;
int n, m, pw2[N << 1], pre = 1, ans;
pair<int, int> edge[N << 1];
int dfsnum, dfn[N], low[N], colnum, col[N], top, sta[N], sz[N], sz2[N];
int f[N];
vector<int> e[N], e2[N];
void tarjan(int u, int fa){
	dfn[u] = low[u] = ++dfsnum;
	sta[++top] = u;
	bool ok = 1;
	for (int v : e[u]){
		if (v == fa && ok){
			ok = 0;
			continue;
		}
		if (!dfn[v]){
			tarjan(v, u);
			low[u] = min(low[v], low[u]);
		}else low[u] = min(dfn[v], low[u]);
	}
	if (dfn[u] == low[u]){
		colnum++;
		do{
			col[sta[top]] = colnum;
			sz[colnum]++;
		}while (sta[top--] != u);
	}
}
void dfs(int u, int fa){
	sz2[u] = 1;
	int g[3];
	g[0] = 1;
	g[1] = g[2] = 0;
	f[u] = pw2[sz[u]] - 1;
	for (int v : e2[u]){
		if (v == fa) continue;
		dfs(v, u);
		g[2] = 1ll * g[2] * (pw2[sz2[v]] + f[v]) % mod;
		g[2] = (g[2] + 1ll * g[1] * f[v]) % mod;
		g[1] = 1ll * g[1] * pw2[sz2[v]] % mod;
		g[1] = (g[1] + 1ll * g[0] * f[v]) % mod;
		g[0] = 1ll * g[0] * pw2[sz2[v]] % mod;
		f[u] = 1ll * f[u] * (pw2[sz2[v]] + f[v]) % mod;
		sz2[u] += sz2[v];
	}
	f[u] = (f[u] + g[2]) % mod;
	ans = (ans + 1ll * f[u] * pw2[colnum - sz2[u]]) % mod;
	f[u] = (f[u] + g[1]) % mod;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	pw2[0] = 1;
	for (int i = 1; i <= 1e6; i++)
		pw2[i] = 1ll * pw2[i - 1] * 2 % mod;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		edge[i] = make_pair(u, v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	tarjan(1, 0);
	for (int i = 1; i <= m; i++){
		int u = edge[i].first, v = edge[i].second;
		if (col[u] == col[v])
			pre = 1ll * pre * 2 % mod;
		else{
			e2[col[u]].push_back(col[v]);
			e2[col[v]].push_back(col[u]);
		}
	}
	for (int i = 1; i <= colnum; i++){
		sort(e2[i].begin(), e2[i].end());
		e2[i].erase(unique(e2[i].begin(), e2[i].end()), e2[i].end());
	}
	dfs(1, 0);
	ans = (ans + mod) % mod;
	pre = (pre + mod) % mod;
	cout << 1ll * ans * pre % mod;
	return 0;
}
