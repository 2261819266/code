#include <cstdio>
#include <cstring>
#define ll long long
#define lowbit(x) ((x) & (-x))
using namespace std;
constexpr int N = 1005;
constexpr int mod = 998244353;
int n, m, c, f;
char str[N];
int a[N][N];
int b[N][N];
ll cc[N], dd[N];
int d[N];
inline void work()
{
	scanf("%d%d%d%d", &n, &m, &c, &f);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s", str + 1);
		for (int j = 1; j <= m; ++j)
			a[i][j] = (str[j] == '1');
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int l = 1, r; l <= m; l = r)
		{
			r = l + 1;
			if (a[i][l])
			{
				b[i][l] = l - 1;
				continue;
			}
			while (r <= m && !a[i][r])
				++r;
			for (int j = l; j < r; ++j)
				b[i][j] = r - 1;
		}
	}
	ll res = 0, ans = 0;
	for (int i = 3; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (b[i - 2][j] > j)
			{
				(cc[j] += b[i - 2][j] - j) %= mod;
			}
			if (b[i - 1][j] < j)
			{
				cc[j] = dd[j] = 0;
				d[j] = i - 1;
			}
			if (b[i][j] >= j)
				(ans += dd[j]) %= mod;
			if (b[i][j] > j)
			{
				(res += cc[j] * (b[i][j] - j)) %= mod;
				(dd[j] += cc[j] * (b[i][j] - j)) %= mod;
			}
		}
	}
	printf("%lld %lld\n", (res * c) % mod, (ans * f) % mod);
	memset(cc, 0, sizeof(cc));
	memset(dd, 0, sizeof(dd));
}
signed main()
{
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	int T = 1, id;
	scanf("%d%d", &T, &id);
	while (T--)
		work();
	return 0;
}
