#include <cstdio>
#define N 3005
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;

int T, n, q, l, r, a[N], b[N], mxA[N][N], mxB[N][N];
unsigned ans;

void open ()
{
	freopen ("match.in", "r", stdin), freopen ("match.out", "w", stdout);
	return ;
}

int main ()
{
	open (), scanf ("%d%d", &T, &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf ("%d", &a[i]);
	}
	for (int i = 1; i <= n; i ++)
	{
		scanf ("%d", &b[i]);
	}
	for (int i = 1; i <= n; i ++)
	{
		for (int j = i; j <= n; j ++)
		{
			mxA[i][j] = max (mxA[i][j - 1], a[j]);
			mxB[i][j] = max (mxB[i][j - 1], b[j]);
		}
	}
	scanf ("%d", &q);
	while (q --)
	{
		scanf ("%d%d", &l, &r), ans = 0;
		for (int i = l; i <= r; i ++)
		{
			for (int j = i; j <= r; j ++)
			{
				ans += mxA[i][j] * mxB[i][j];
			}
		}
	}
	printf ("%u", ans);
	return 0;
}
