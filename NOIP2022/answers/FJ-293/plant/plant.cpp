#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

typedef long long ll;
#define MAXN (1010)
#define MOD (998244353ll)

char a[MAXN][MAXN];
ll n, m, t, id, c, f, AK1, AK2;	// AK1 = ans1, AK2 = ans2
ll a2[MAXN][MAXN], c2[MAXN][MAXN];

int main()
{
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	
	scanf("%lld%lld", &t, &id);
	while (t--)
	{
		scanf("%lld%lld%lld%lld", &n, &m, &c, &f);
		for (int i = 1; i <= n; i++)
			scanf("%s", a[i] + 1);
		
		// cal a2.
		for (int i = 1, i2; i <= n; i++)
		{
			i2 = 0;
			for (int j = m; j; j--)
			{
				if (a[i][j] == '0')
				{
					a2[i][j] = ++i2;
				}
				else {i2 = 0; continue;}
			}
		}
		
		// cal c2.
		deque<int> qu, pos;
		for (int j = 1, l; j < m; j++)
		{
			l = -1, qu.clear(), pos.clear();
			for (ll i = 1, i2 = 0; i <= n; i++)
			{
				if (a[i][j] == '1') l = -1, i2 = 0, qu.clear(), pos.clear();
				else if (a2[i][j + 1])
				{
					qu.push_back(a2[i][j + 1]), pos.push_back(i);
					while (pos.size() && i - pos.front() + 1 >= 3)
						i2 = (i2 + qu.front()) % MOD,
						qu.pop_front(), pos.pop_front();
					c2[i][j] = i2 * a2[i][j + 1] % MOD,
					AK1 = (AK1 + c2[i][j]) % MOD;
				}
			}
		}
		
		// cal AK2.
		for (ll j = 1, l, l2; j < m; j++)
		{
			l = -1, l2 = 0;
			for (int i = 1; i <= n; i++)
			{
				if (a[i][j] == '1') l = -1, l2 = 0;
				else
				{
					if (l == -1) l = i, l2 = 0;
					if (!a2[l][j + 1]) continue;
					if (i - l + 1 >= 4)
						AK2 = (AK2 + l2) % MOD;
					if (i - l + 1 >= 3)
						l2 = (l2 + c2[i][j]) % MOD;
				}
			}
		}
		
		printf("%lld %lld", AK1 * c, AK2 * f);
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

4 2

6 + 10 + 15 + 4 + 1
*/
