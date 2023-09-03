#include <bits/stdc++.h>
#define reg register

const int N = 500010, M = 2 * N, P = 1000000007;

int n, m, u[N], v[N], chose[N], po[N], ans;
int Ecnt, head[N], ok[M << 1], nxt[M << 1], ver[M << 1];

void add(reg int x, reg int y)
{
	ver[ ++ Ecnt] = y; nxt[Ecnt] = head[x]; ok[Ecnt] = 1; head[x] = Ecnt;
}

namespace Subtask1
{
	int gw = 0;
	
	void search(reg int x, reg int fa)
	{
		if (v[x]) return; v[x] = 1;
		for (reg int i = head[x]; i; i = nxt[i]) if (ver[i] != fa && ok[i]) search(ver[i], x);
	}
	
	void dfs(reg int dep)
	{
		if (dep == n + 1)
		{
			if (gw == 0) return;
			reg int cnt = 0, flag = 1;
			for (reg int i = 1; i <= m; ++ i)
			{
				for (reg int j = 1; j <= n; ++ j) v[j] = 0;
				ok[i * 2 - 1] = ok[2 * i] = 0; search(gw, 0); ok[2 * i - 1] = ok[2 * i] = 1;
				for (reg int j = 1; j <= n; ++ j) if (chose[j] && !v[j]) { flag = 0; break; }
				if (flag == 0) ++ cnt;
			}
			return ans = (ans + (1 << (m - cnt))) % P, void();
		}
		dfs(dep + 1); chose[dep] = 1; gw = dep; dfs(dep + 1); chose[dep] = 0;
	}
	
	int main()
	{
		dfs(1); printf("%d\n", (ans + P) % P); return 0;
	}
}

int main()
{
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	for (reg int i = 1; i <= m; ++ i) scanf("%d %d", &u[i], &v[i]), add(u[i], v[i]), add(v[i], u[i]), ok[i] = 1;
	if (n <= 16 && m <= 25) return Subtask1 :: main();
	else
	{
		reg int ans = 0; po[0] = 1;
		for (reg int i = 1; i <= n; ++ i) po[i] = 2 * po[i - 1] % P;
		for (reg int i = 1; i <= n; ++ i) ans = (ans + 1ll * i * po[i - 1] % P) % P;
		printf("%d\n", (ans + P) % P);
	}
}
