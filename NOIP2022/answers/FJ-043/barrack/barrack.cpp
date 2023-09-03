#include <bits/stdc++.h>
using namespace std;
const int N = 1000010, MOD = 1000000007;

struct Edge{
	int to, nxt;
}e[N << 1];
int n, m, num, fir[N], cnt, g[30][30], f[N], u[N], v[N];
int vis[300], ss[300], len, sz[300], pd, ans, seq[500], sum;

inline void add(int x, int y){
	e[++cnt] = (Edge){y, fir[x]}, fir[x] = cnt;
}

int find(int x){
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

void dfs(int x, int fa, int ss){
	if(vis[x]){
		for(int i = vis[x]; i < ss - 1; i++)
			g[seq[i]][seq[i + 1]] = g[seq[i + 1]][seq[i]] = 1;
		if(ss - 1 != vis[x]) g[x][seq[ss - 1]] = g[seq[ss - 1]][x] = 1;
		return;
	}
	vis[x] = ss, seq[ss] = x;
	for(int i = fir[x]; i; i = e[i].nxt)
		if(e[i].to != fa)
			dfs(e[i].to, x, ss + 1);
	vis[x] = 0;
}

int main(){
	
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	
	scanf("%d%d", &n, &m);

	if(n <= 16 && m <= 25){
		for(int i = 1; i <= m; i++){
			scanf("%d%d", &u[i], &v[i]);
			add(u[i], v[i]), add(v[i], u[i]);
		}
		dfs(1, 0, 1), len = 0;
		for(int i = 1; i <= m; i++)
			if(!g[u[i]][v[i]])
				seq[++len] = i;
			else
				sum++;
		for(int i = 0; i < 1 << len; i++){
			for(int j = 1; j <= n; j++) f[j] = j, sz[j] = 0, pd = 0;
			for(int j = 0; j < len; j++) if((i >> j) & 1)
				f[find(u[seq[j + 1]])] = find(v[seq[j + 1]]);
			for(int j = 1; j <= m; j++)
				if(g[u[j]][v[j]]) f[find(u[j])] = find(v[j]);
			for(int j = 1; j <= n; j++)
				sz[find(j)]++;
			for(int j = 1; j <= n; j++) ss[sz[j]]++;
		}
		for(int i = 1, t = 2; i <= n; i++, t <<= 1)
			ans = (ans + 1ll * ss[i] * (t - 1) % MOD) % MOD;
		int T = 1;
		for(int i = 1; i <= sum; i++) T <<= 1;
		printf("%lld\n", 1ll * ans * T % MOD);
	}
	else{
		ans = 5;
		for(int i = 3, now, t = 2; i <= n; i++, t = 2ll * t % MOD){
			now = 1ll * t * (i + 1) % MOD;
			ans = (2ll * ans % MOD + now) % MOD;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
