#include <cstdio>
#define ull unsigned long long
using namespace std;
template <typename T>
inline void ckmax(T &x, T y)
{
	if (x < y)
		x = y;
}
constexpr int N = 3e3 + 5;
int n, m, a[N], b[N];
ull h[N][N];
signed main()
{
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	int T;
	scanf("%d%d", &T, &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &b[i]);
	scanf("%d", &m);
	for (int j = 1; j <= n; ++j)
	{
		int max1 = -1, max2 = -1;
		for (int k = j; k <= n; ++k)
		{
			ckmax(max1, a[k]);
			ckmax(max2, b[k]);
			h[j][k] = h[j][k - 1] + (ull)max1 * (ull)max2;
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		ull ans = 0;
		int l, r;
		scanf("%d%d", &l, &r);
		for (int j = l; j <= r; ++j)
			ans += h[j][r];
		printf("%llu\n", ans);
	}
	return 0;
}
