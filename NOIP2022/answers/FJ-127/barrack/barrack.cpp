#include <bits/stdc++.h>

template < typename T >
inline void read(T &cnt)
{
	cnt = 0; char ch = getchar(); bool op = 1;
	for (; ! isdigit(ch); ch = getchar())
		if (ch == '-') op = 0;
	for (; isdigit(ch); ch = getchar())
		cnt = cnt * 10 + ch - 48;
	cnt = op ? cnt : -cnt;
} 

const int M = 50 + 10;
const int N = 50 + 10;
const int mod = 1e9 + 7;

int n, m;

inline int quick_pow(int a, int b)
{
	int ret = 1;
	for (; b; b >>= 1)
	{
		if (b & 1) ret = 1ll * ret * a % mod;
		a = 1ll * a * a % mod;
	} 
	return ret % mod;
}

namespace subtask1
{
	int u[M], v[M], col[N];
	struct E
	{
		int head[N], nxt[M * 2], to[M * 2], ID[M * 2], tot;
		inline void add(int u, int v, int id)
		{
			nxt[++ tot] = head[u];
			head[u] = tot;
			to[tot] = v;	
			ID[tot] = id; 
		}
	} E1, E2;
	int choice[N], vis[N], siz[N], cnt[N], ct, tag[N];
	long long answer = 0;

	inline void dfs(int u, int fa)
	{
		vis[u] = 1; siz[u] = 1; col[u] = ct;
		for (int i = E1.head[u]; i; i = E1.nxt[i])
		{
			int v = E1.to[i];
			if (! choice[E1.ID[i]] || vis[v] || v == fa) continue;
			vis[v] = 1;
			dfs(v, u);
			siz[u] += siz[v];
		} 
	} 

	inline int dfs2(int u, int fa, int benyuan)
	{
		vis[u] = 1;
		for (int i = E2.head[u]; i; i = E2.nxt[i])
		{
			int v = E2.to[i]; 
			if (v == fa) continue;
			if (v == benyuan)
			{
				if (tag[u] == 0)
				{ 
					cnt[benyuan] += cnt[u];
					cnt[u] = 0;
				}
				tag[u] = benyuan;
				continue;
			}
			if (vis[v]) continue;
			if (dfs2(v, u, benyuan))
			{
				if (tag[u] == 0)
				{ 
					cnt[benyuan] += cnt[u];
					cnt[u] = 0;
				}
				tag[u] = benyuan;
			}
		}
		return tag[u];
	}
	int edge[20][20];
	inline void calc()
	{
		ct = 0; 
		memset(vis, 0, sizeof(vis)); 
		memset(cnt, 0, sizeof(cnt));
		memset(edge, 0, sizeof(edge));

		for (int i = 1; i <= n; ++ i)
			if (! vis[i])
			{
				++ ct;
				dfs(i, 0);
				cnt[ct] = siz[i];
			}
		
		for (int i = 1; i <= m; ++ i)
		{
			if (col[u[i]] == col[v[i]]) continue;
			edge[col[u[i]]][col[v[i]]] ++; edge[col[v[i]]][col[u[i]]] ++;
			if (edge[col[u[i]]][col[v[i]]] == 2)
			{
				cnt[col[v[i]]] += cnt[col[u[i]]];
				cnt[col[u[i]]] = 0;
				col[u[i]] = col[v[i]];
			}
		}

		E2.tot = 0; memset(E2.head, 0, sizeof(E2.head));
		for (int i = 1; i <= m; ++ i)
		{
			if (col[u[i]] == col[v[i]]) continue;
			E2.add(col[u[i]], col[v[i]], 0);
			E2.add(col[v[i]], col[u[i]], 0);
		}
		memset(vis, 0, sizeof(vis)); 
		memset(tag, 0, sizeof(tag)); 
		for (int i = 1; i <= ct; ++ i)
		{
			if (! tag[i] && cnt[i])
			{
				tag[i] = i;
				dfs2(i, 0, i);
				answer = (answer + quick_pow(2, cnt[i]) - 1) % mod;
				answer = (answer + mod) % mod;
			}
		}
	}
	inline void search(int step)
	{
		if (step == m + 1)
		{
			calc();	
			return;
		} 
		choice[step] = 1;
		search(step + 1);
		choice[step] = 0;
		search(step + 1);
	}

	inline void solve()
	{
		for (int i = 1; i <= m; ++ i)
		{
			read(u[i]), read(v[i]);
			E1.add(u[i], v[i], i);	
			E1.add(v[i], u[i], i);
		}

		search(1);

		printf("%lld\n", answer);
	}
} 

int main()
{
	freopen("barrack.in", "r", stdin); 
	freopen("barrack.out", "w", stdout); 
	read(n), read(m);
	subtask1::solve();
	return 0;
}
