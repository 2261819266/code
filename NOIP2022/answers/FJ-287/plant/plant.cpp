#include <cstdio>
#define MOD 998244353
#define N 1005
using namespace std;

int T, idx, n, m, C, F, cnt, ansC, ansF, pos[N][N], dis[N];
char s[N][N];
bool a[N][N];

void open ()
{
	freopen ("plant.in", "r", stdin), freopen ("plant.out", "w", stdout);
	return ;
}

int main ()
{
	open (), scanf ("%d%d", &T, &idx);
	while (T --)
	{
		scanf ("%d%d%d%d", &n, &m, &C, &F), ansC = ansF = 0;
		if (m == 1 || !C && !F)
		{
			puts ("0 0");
			continue;
		}
		for (int i = 1; i <= n; i ++)
		{
			scanf ("%s", s[i] + 1), cnt = 0;
			for (int j = 1; j <= m; j ++)
			{
				a[i][j] = s[i][j] ^ '0';
			}
			for (int j = m; j; j --)
			{
				pos[i][j] = cnt = a[i][j] ? 0 : cnt + 1;
			}
		}
		for (int j = 1; j <= m; j ++)
		{
			cnt = 0;
			for (int i = 3; i <= n; i ++)
			{
				if (a[i][j])
				{
					cnt = 0;
					continue;
				}
				if (!a[i - 2][j] && !a[i - 1][j])
				{
					cnt += (pos[i - 2][j] - 1);
				}
				ansC = (ansC + (long long) (pos[i][j] - 1) * cnt) % MOD;
			}
		}
		for (int j = 1; j <= m; j ++)
		{
			cnt = 0;
			for (int i = n; i; i --)
			{
				dis[i] = cnt = a[i][j] ? 0 : cnt + 1;
			}
			cnt = 0;
			for (int i = 3; i < n; i ++)
			{
				if (a[i][j])
				{
					cnt = 0;
					continue;
				}
				if (!a[i - 2][j] && !a[i - 1][j])
				{
					cnt += (pos[i - 2][j] - 1);
				}
				ansF = (ansF + (long long) (pos[i][j] - 1) * cnt * dis[i + 1]) % MOD;
			}
		}
		printf ("%d %d\n", C * ansC, F * ansF);
	}
	return 0;
}

/*
1 0
4 3 1 1
001
010
000
000
*/
