#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL N = 1010, mod = 998244353;

LL n, m, c, f;
char g[N][N];
LL cntc, cntf;
LL t1[N][N], t2[N][N];

bool check_C(LL x, LL xx, LL y, LL yy, LL yyy)
{
	for (LL i = y; i <= yy; i ++ )
		if (g[x][i] == '1')
			return false;
	for (LL i = y; i <= yyy; i ++ )
		if (g[xx][i] == '1')
			return false;
	for (LL i = x; i <= xx; i ++ )
		if (g[i][y] == '1')
			return false;
	return true;
}

void baoli_C()
{
	for (LL x = 1; x <= n; x ++ )	
		for (LL xx = x + 2; xx <= n; xx ++ )
			for (LL y = 1; y <= m; y ++ )
				for (LL yy = y + 1; yy <= m; yy ++ )
					for (LL yyy = y + 1; yyy <= m; yyy ++ )
						if (check_C(x, xx, y, yy, yyy))
						{
							cout << x << ' ' << xx << ' ' << y << ' ' << yy << ' ' << yyy << endl;
							cntc = (cntc + 1) % mod;
						}
}

bool check_F(LL x, LL xx, LL xxx, LL y, LL yy, LL yyy)
{
	for (LL i = y; i <= yy; i ++ )
		if (g[x][i] == '1')
			return false;
	for (LL i = y; i <= yyy; i ++ )
		if (g[xx][i] == '1')
			return false;
	for (LL i = x; i <= xxx; i ++ )
		if (g[i][y] == '1')
			return false;
	return true;
}

void baoli_F()
{
	for (LL x = 1; x <= n; x ++ )	
		for (LL xx = x + 2; xx <= n; xx ++ )
			for (LL xxx = xx + 1; xxx <= n; xxx ++ )
				for (LL y = 1; y <= m; y ++ )
					for (LL yy = y + 1; yy <= m; yy ++ )
						for (LL yyy = y + 1; yyy <= m; yyy ++ )
							if (check_F(x, xx, xxx, y, yy, yyy))
								cntf = (cntf + 1) % mod;
}

void baoli()
{
	baoli_C();
	baoli_F();
}

void work_C()
{
	LL now = 0;
	for (LL i = 1; i <= n; i ++ )
		for (LL j = 1; j <= m; j ++ )
		{
			if (t1[i][j] <= 1) continue;
			LL sum = 0;
			for (LL k = i + 2; k <= i + t2[i][j] - 1; k ++ )
				if (t1[k][j] > 1)
					sum = (sum + t1[k][j] - 1) % mod;
			now = (now + sum * (t1[i][j] - 1)) % mod;
		}
	cntc = now;
}

void work_F()
{
	LL now = 0;
	for (LL i = 1; i <= n; i ++ )
		for (LL j = 1; j <= m; j ++ )
		{
			if (t1[i][j] <= 1) continue;
			LL sum = 0;
			for (LL k = i + 2; k <= i + t2[i][j] - 2; k ++ )
				if (t1[k][j] > 1)
					sum = (sum + (t1[k][j] - 1) * (t2[k][j] - 1) % mod) % mod;
			now = (now + sum * (t1[i][j] - 1)) % mod;
		}
	cntf = now;
}

void on3()
{
	for (LL i = 1; i <= n; i ++ )
		for (LL j = 1; j <= m; j ++ )
		{
			LL x = i, y = j;
			while (g[x][y] == '0') y ++ ;
			t1[i][j] = y - j;
		}
	for (LL i = 1; i <= n; i ++ )
		for (LL j = 1; j <= m; j ++ )
		{
			LL x = i, y = j;
			while (g[x][y] == '0') x ++ ;
			t2[i][j] = x - i;
		}
	work_C();
	work_F();
}

int main()
{
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	LL T, id;
	scanf("%lld%lld", &T, &id);
	while (T -- )
	{
		scanf("%lld%lld%lld%lld", &n, &m, &c, &f);
		c %= mod, f %= mod;
		for (LL i = 1; i <= n; i ++ ) scanf("%s", g[i] + 1);
		if (!c && !f)
		{
			printf("0 0\n");
			continue;
		}
		if (n <= 10)
		{
			baoli();
			printf("%lld %lld\n", c * cntc % mod, f * cntf % mod);
			continue;
		}
		on3();
		printf("%lld %lld\n", c * cntc % mod, f * cntf % mod);
	}
	return 0;
}
