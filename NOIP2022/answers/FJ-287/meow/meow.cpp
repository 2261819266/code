#include <cstdio>
#define M 2000005
#define N 305
#define get(x) (((x)-1)%(n-1)+1)
#define swap(a,b) (a)^=(b),(b)^=(a),(a)^=(b)
using namespace std;

int T, n, m, k, x, cnt, cnt_, a[M], st[N][5], tot[N], ans[M][3], pt[N << 1], nth[M];

void open ()
{
	freopen ("meow.in", "r", stdin), freopen ("meow.out", "w", stdout);
	return ;
}

int main ()
{
	open (), scanf ("%d", &T);
	while (T --)
	{
		scanf ("%d%d%d", &n, &m, &k), cnt = 0;
		for (int i = 1; i <= m; i ++)
		{
			scanf ("%d", &a[i]);
		}
		if (k == n - 1 << 1)
		{
			for (int i = 1; i <= m; i ++)
			{
				if (st[get (a[i])][1] == a[i])
				{
					ans[++ cnt][0] = 1, ans[cnt][1] = n;
					ans[++ cnt][0] = 2, ans[cnt][1] = get (a[i]), ans[cnt][2] = n;
					continue;
				}
				if (st[get (a[i])][tot[get (a[i])]] == a[i])
				{
					tot[get (a[i])] --;
				}
				else
				{
					st[get (a[i])][++ tot[get (a[i])]] = a[i];
				}
				ans[++ cnt][0] = 1, ans[cnt][1] = get (a[i]);
			}
		}
		else
		{
			for (int i = 1; i < k; i ++)
			{
				pt[i] = get (i);
			}
			pt[k] = n, cnt_ = 0;
			for (int i = 1; i <= m; i ++)
			{
				if (st[pt[a[i]]][1] == a[i])
				{
					if (tot[n])
					{
						swap (pt[a[i]], pt[k]);
						ans[++ cnt][0] = 1, ans[cnt][1] = n, nth[++ cnt_] = i;
//						for (int i = 1; i <= n; i ++)
//						{
//							
//						}
					}
					ans[++ cnt][0] = 1, ans[cnt][1] = n;
					ans[++ cnt][0] = 2, ans[cnt][1] = pt[a[i]], ans[cnt][2] = n;
					continue;
				}
				if (st[pt[a[i]]][tot[pt[a[i]]]] == a[i])
				{
					tot[pt[a[i]]] --;
				}
				else
				{
					st[pt[a[i]]][++ tot[pt[a[i]]]] = a[i];
				}
				ans[++ cnt][0] = 1, ans[cnt][1] = pt[a[i]];
			}
		}
		printf ("%d\n", cnt);
		for (int i = 1; i <= cnt; i ++)
		{
			if (ans[i][0] == 1)
			{
				printf ("1 %d\n", ans[i][1]);
			}
			else
			{
				printf ("2 %d %d\n", ans[i][1], ans[i][2]);
			}
		}
	}
	return 0;
}

/*
1
2 4 2
1 2 1 2
*/
