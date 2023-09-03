#include<bits/stdc++.h>
#define ll long long
const int N = 1005;
const int Mod = 998244353;
using namespace std;
int T, id, n, m, C, F;
int q[N][N], f[N][N];
int lc[N][N];
ll ansc, ansf;
bool b[N][N];
string s;
int main()
{
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	scanf("%d%d", &T, &id);
	for(int z = 1; z <= T; z++)
	{
		memset(f, 0, sizeof 0);
		scanf("%d%d%d%d", &n, &m, &C, &F);
		if(C == 0 && F == 0)
		{
			printf("0 0\n");
			continue;
		}
		for(int i = 1; i <= n; i++)
		{
			cin >> s;
			for(int j = 0; j < m; j++)
			{
				b[i][j + 1] = (s[j] == '1') ? false : true;
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = m; j >= 1; j--)
			{
				if(b[i][j] && b[i][j + 1])
				{
					q[i][j] = q[i][j + 1] + 1;
				}
				if(b[i][j] && !b[i][j + 1])
				{
					q[i][j] = 0;
				}
			}
		}
		for(int i = n; i >= 1; i--)
		{
			for(int j = 1; j <= m; j++)
			{
				if(b[i][j] && b[i + 1][j])
				{
					f[i][j] = q[i][j] + f[i + 1][j];
				}
				if(b[i][j] && !b[i + 1][j])
				{
					f[i][j] = q[i][j];
				}
			}
		}
		for(int i = 1; i <= n - 2; i++)
		{
			for(int j = 1; j < m; j++)
			{
				if(b[i][j] && b[i + 1][j] && b[i + 2][j])
				{
					ansc = (ansc + (q[i][j] * f[i + 2][j])) % Mod;
				}
			}
		}
		if(F == 0)
		{
			printf("%lld %lld\n", ansc, ansf);
			continue;
		}
		for(int i = n; i >= 1; i--)
		{
			for(int j = 1; j <= m; j++)
			{
				if(b[i][j] && b[i + 1][j])
				{
					lc[i][j] = lc[i + 1][j] + 1;
				}
				if(b[i][j] && !b[i + 1][j])
				{
					lc[i][j] = 0;
				}
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(b[i][j] && b[i + 1][j] && b[i + 2][j])
				{
					for(int k = i + 2, cnt = 1; cnt <= lc[i + 1][j]; k++, cnt++)
					{
						ansf = (ansf + (q[i][j] * q[k][j] * lc[k][j])) % Mod;
					}
				}
			}
		}
		printf("%lld %lld\n", ansc % Mod, ansf % Mod);
	}
	return 0;
}