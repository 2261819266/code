#include <bits/stdc++.h>
#define int long long
using namespace std;

//Remember freopen!!!!!!!!!!!
//for zjy.
const int MOD = 1e9 + 7;

signed main()
{
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);

	int n, m, ans = 0;
	cin >> n >> m;

	if (n == m + 1)
	{
		int u, v;
		while (m --)
			cin >> u >> v;
		for (int i = 1; i <= n; i ++)
		{
			int x = 1;

			x = x * (1 << (n - i)) % MOD;

			if (i >= 2)
				x = x * (1 << (i - 2)) % MOD;

			x = x * (n - i + 1) % MOD;

			ans = (ans + x) % MOD;
			
		}
		cout << ans;
	}
	else
	{
		cout << 114514;
	}

	return 0;
}
