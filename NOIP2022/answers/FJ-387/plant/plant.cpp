#include <bits/stdc++.h>

using namespace std;
const int N = 1010, mod = 998244353;
int a[N][N];
int u[N][N], r[N][N], d[N][N];
int sr[N][N];

inline int read()
{
	int x = 0, y = 1; char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') y = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * y;
}

inline int mul(int x, int y)
{
	return 1ll * x * y % mod;
}

inline int get_mod(int x)
{
	return (x % mod + mod) % mod;
}

int main()
{
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	int t = read(), id = read();
	while (t--)
	{
		memset(u, 0, sizeof u);
		memset(r, 0, sizeof r);
		memset(d, 0, sizeof d);
		memset(sr, 0, sizeof sr);
		int n = read(), m = read(), c = read(), f = read();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				char c;
				cin >> c;
				a[i][j] = c - '0';
			}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				u[i][j] = a[i][j] == 1 ? i : u[i - 1][j];
		for (int i = 1; i <= n; i++) r[i][m + 1] = m + 1;
		for (int i = n; i; i--)
			for (int j = m; j; j--)
				r[i][j] = a[i][j] == 1 ? j : r[i][j + 1];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				sr[i][j] = get_mod(sr[i - 1][j] + r[i][j] - j - 1);
		for (int i = 1; i <= m; i++) d[n + 1][i] = n + 1;	
		for (int i = n; i; i--)
			for (int j = m; j; j--)
				d[i][j] = a[i][j] == 1 ? i : d[i + 1][j];
		int resc = 0, resf = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				if (i - u[i][j] <= 2) continue;
				resc = get_mod(resc + mul(r[i][j] - j - 1, get_mod(sr[i - 2][j] - sr[u[i][j]][j])));
			}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				if (i - u[i][j] <= 2) continue;
				resf = get_mod(resf + mul(mul(r[i][j] - j - 1, get_mod(sr[i - 2][j] - sr[u[i][j]][j])), d[i][j] - i - 1));
			}
		printf("%d %d\n", mul(c, resc), mul(f, resf));
	}
	return 0;
}