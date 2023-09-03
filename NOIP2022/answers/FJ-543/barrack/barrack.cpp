#include <bits/stdc++.h>
using namespace std;
int n, m;
bool b[500005] = {0};
long long d[500005] = {0};
const long long MOD = 1000000007;
long long ans = 0;

int getsum(int x)
{
	return (x + 1) * x / 2;
}

long long qpow(long long s)
{
	long long r = 1;
	long long a = 2;
	while (s)
	{
		if (s & 1)
		{
			r *= a;
			r %= MOD;
		}
		a *= a;
		a %= MOD;
		s >>= 1;
	}
	return r;
}

int main()
{
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++)
	{
		cin >> u >> v;
		d[u]++, d[v]++;
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			long long cnt1 = 0;
			for (int k = i; k <= j; k++)
				if (d[k] > 1)
					cnt1 += 1;
			if (cnt1 == 0) cnt1 = 1;
			long long s = m - (j - i);
			long long cnt2 = qpow(s);
			long long cnt3 = cnt1 * cnt2;
			ans += cnt3;
			ans %= MOD;
		}
	}
	cout << ans << endl;
	//There was something wrong with my code(TAT).
	//Yes,I can't do this problem,but I am a junior student,so...
	//My think:make a graph and dfs().
	//But there was something wrong with my dfs().
	//So I delete dfs().
	//Hahaha.
	return 0;
}
