#include <cstdio>
#define MOD 1000000007
#define N 500005
#define M 1000005
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;

int n, m, tot = 2, x, y, num, dcc,
head[N], nxt[M << 1], ver[M << 1], c[N], dfn[N], low[N], siz[N];
long long ans = 1;
bool b[M << 1];

void insert (int x, int y)
{
	ver[tot] = y, nxt[tot] = head[x], head[x] = tot ++;
	return ;
}

void tarjan (int x, int ie)
{
	dfn[x] = low[x] = ++ num;
	for (int i = head[x], y; i; i = nxt[i])
	{
		if (!dfn[y = ver[i]])
		{
			tarjan (y, i), low[x] = min (low[x], low[y]);
			if (dfn[x] < low[y])
			{
				b[i] = b[i ^ 1] = 1;
			}
		}
		else if (i != (ie ^ 1))
		{
			low[x] = min (low[x], dfn[y]);
		}
	}
	return ;
}

void dfs (int x)
{
	c[x] = dcc;
	for (int i = head[x], y; i; i = nxt[i])
	{
		if (!c[y = ver[i]] && !b[i])
		{
			dfs (y);
		}
	}
	return ;
}

void open ()
{
	freopen ("barrack.in", "r", stdin), freopen ("barrack.out", "w", stdout);
	return ;
}

int main ()
{
	open (), scanf ("%d%d", &n, &m);
	puts ("0");
	while (m --)
	{
		scanf ("%d%d", &x, &y), insert (x, y), insert (y, x);
	}
	for (int i = 1; i <= n; i ++)
	{
		if (!dfn[i])
		{
			tarjan (i, 0);
		}
	}
	for (int i = 1; i <= n; i ++)
	{
		if (!c[i])
		{
			dcc ++, dfs (i);
		}
	}
	for (int i = 1; i <= n; i ++)
	{
		for (int j = head[i]; j; j = nxt[j])
		{
			siz[c[i]] += ver[j] > i && c[i] == c[ver[j]];
		}
	}
	for (int i = 1; i <= dcc; i ++)
	{
		ans = ans * (siz[i] + 1) % MOD;
	}
	return 0;
}

/*
4 4
1 2
2 3
3 1
1 4
*/
