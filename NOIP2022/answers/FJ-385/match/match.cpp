#include <bits/stdc++.h>
#define FOR(x, l, r) for (int x = l; x <= r; ++ x)
#define ROF(x, r, l) for (int x = r; x >= l; -- x)
using namespace std;
typedef unsigned long long ull;
const int M = 250050;
int T, n, Q, l[M], r[M];
ull a[M], b[M];
int main()
{
	ios::sync_with_stdio(false);
	freopen("match.in" , "r" , stdin);
	freopen("match.out", "w" , stdout);
	
	cin >> T >> n;
	FOR (i, 1, n)
	{
		cin >> a[i];
	}
	FOR (i, 1, n)
	{
		cin >> b[i];
	}
	cin >> Q;
	FOR (i, 1, Q)
	{
		cin >> l[i] >> r[i];
	}
	if (n <= 3000)
	{
		ull res, ma1, ma2;
		FOR (i, 1, Q)
		{
			res = 0;
			FOR (x, l[i], r[i])
			{
				ma1 = 0, ma2 = 0;
				FOR (y, x, r[i])
				{
					ma1 = max(ma1, a[y]);
					ma2 = max(ma2, b[y]);
					res += ma1 * ma2;	
				}
			}
			cout << res << endl;
		}
	}
	return 0;
}
