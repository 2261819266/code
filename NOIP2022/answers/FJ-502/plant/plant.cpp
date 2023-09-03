#include <bits/stdc++.h>
#define int long long
using namespace std;

//Remember freopen!!!!!!!!!!!
//for zjy.

const int MOD = 998244353;
const int MAXN = 1e3 + 107;
int t, n, m, c, f, vc, vf, id;
bool a[MAXN][MAXN];
int x[MAXN][MAXN], y[MAXN][MAXN];
int x2[MAXN][MAXN];

void init()
{
	memset(x, 0, sizeof(x));
	memset(y, 0, sizeof(y));
	memset(a, 0, sizeof(a));
	memset(x2, 0, sizeof(x2));
}

void debugx()
{
	cout << endl;
	for (int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
			cout << x[i][j] << ' ';
		cout << endl;
	}
}

void debugy()
{
	cout << endl;
	for (int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
			cout << y[i][j] << ' ';
		cout << endl;
	}
}

void debugx2()
{
	cout << endl;
	for (int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
			cout << x2[i][j] << ' ';
		cout << endl;
	}
}

signed main()
{
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);

	scanf("%lld %lld", &t, &id);

	while (t --)
	{
		init();
		
		scanf("%lld %lld %lld %lld", &n, &m, &c, &f);
		vc = vf = 0;

		char ch;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= m; j ++)
			{
				while (!((ch = getchar()) == '0' || ch == '1'));
				a[i][j] = bool(ch - '0');
			}

		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= m + 1; j ++)
				if (a[i][j] || j == m + 1)
				{
					int k = 0, j2 = j - 1;
					while (a[i][j2] == 0 && j2 >= 1)
					{
						x[i][j2] = k;
						k ++, j2 --;
					}
				}

		for (int i = 1; i <= n + 1; i ++)
			for (int j = 1; j <= m; j ++)
				if (a[i][j] || i == n + 1)
				{
					int k = 0, i2 = i - 1;
					while (a[i2][j] == 0 && i2 >= 1)
					{
						y[i2][j] = k ++, i2 --;
					}
				}

		for (int i = 0; i <= n; i ++)
			for (int j = 1; j <= m; j ++)
				if (a[i][j] || i == 0)
				{
					int i2 = i + 1;
					while (a[i2][j] == 0 && i2 <= n)
					{
						x2[i2][j] = x2[i2 - 1][j] + x[i2 - 1][j];
						i2 ++;
					}
				}

		for (int i = 3; i <= n; i ++)
			for (int j = 1; j <= m - 1; j ++)
			{
//				printf("%d %d %d %d\n", i, j, x2[i - 1][j], x[i - 1][j]);
				int cc = x[i][j] * (x2[i][j] - x[i - 1][j]);
				vc = (vc + cc) % MOD;
				vf = (vf + cc * y[i][j]) % MOD;
			}

//		debugx();
//		debugy();
//		debugx2();

		vc *= c, vf *= f;
		printf("%lld %lld\n", vc, vf);
	}

	return 0;
}

/*

3 0
4 3 1 1
001
010
000
000
6 6 1 1
000010
011000
000110
010000
011000
000000
16 12 1 1
000000000001
011111111111
000000000011
011111111111
010011111111
010111100011
010011101111
011111100011
111111111111
000011111111
011111111111
000000111111
011111000111
011111011111
011111000111
011111011111


*/