
#include <bits/stdc++.h>

using namespace std; const int maxn = 1e6 + 5, mod = 1e9 + 7; typedef long long ll;

int n, m;

vector<pair<int, int> > G[maxn];

vector<int> T[maxn];

int df[maxn], lw[maxn], dt; bool br[maxn];

void Tarjan(int u, int FA)
{
	df[u] = lw[u] = ++dt;
	for (auto v : G[u]) if (v.first != FA)
	{
		if (!df[v.second])
		{
			Tarjan(v.second, v.first), lw[u] = min(lw[u], lw[v.second]);
			if (lw[v.second] > df[u])
			{
				br[v.first] = 1;
			}
		}
		else lw[u] = min(lw[u], df[v.second]);
	}
}

int cl[maxn], tcl, num[maxn];

void color(int u)
{
	if (cl[u]) return; cl[u] = tcl, num[tcl]++;
	for (auto v : G[u]) if (!br[v.first]) color(v.second);
}

int pw[maxn];

int f[maxn], ans, sz[maxn], g[maxn];

void dp(int u, int fa)
{
	sz[u] = 1, f[u] = 1, g[u] = pw[num[u]] - 1;
	for (int v : T[u]) if (v != fa)
	{
		dp(v, u);
		sz[u] += sz[v];
		g[u] = (ll)g[u] * ((ll)pw[sz[v] - 1] + (ll)f[v] + (ll)g[v]) % mod;
//		cerr << "trans: " << ((ll)pw[sz[v] - 1] + (ll)f[v] + (ll)g[v]) << endl;
		g[u] = (g[u] + (ll)f[u] * (g[v])) % mod;
//		cerr << "trans: " << f[u] << ' ' << 
		f[u] = (ll)f[u] * (pw[sz[v] - 1] + f[v]) % mod;
	}
	ans = (ans + (ll)g[u] * (u == 1 ? 1 : pw[tcl - sz[u] - 1])) % mod;
//	cerr << u << ' ' << fa << ' ' << g[u] << ' ' << f[u] << endl;
}

int main()
{
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; i++) scanf("%d%d", &u, &v), G[u].push_back({ i, v }), G[v].push_back({ i, u });
	Tarjan(1, 0);
//	cerr << "dt: " << dt << endl;
	for (int i = 1; i <= n; i++) if (!cl[i]) ++tcl, color(i);
//	cerr << "cr: "; for (int i = 1; i <= n; i++) cerr << cl[i] << ' '; cerr << endl;
	for (int i = 1; i <= n; i++) for (auto j : G[i]) if (br[j.first]) T[cl[i]].push_back(cl[j.second])/*, cerr << cl[i] << ' ' << cl[j.second] << endl*/;
	for (int i = pw[0] = 1; i <= n; i++) pw[i] = (ll)pw[i - 1] * 2 % mod;
	dp(1, 0);
//	return 0 * printf("%d\n", (ans - pw[tcl - 1] + mod) % mod);
	int T2 = m - (tcl - 1); while (T2--) ans = (ll)ans * 2 % mod;
	return 0 * printf("%d\n", ans);
}


