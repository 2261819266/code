//NOIP2022 RP++
#include <bits/stdc++.h>
using namespace std;
int T, n, m, k, a[305], s[305][100005], h[301], t[305], back[100005][3], backtop = 0;
bool dfs(int u)
{
	if (u == m + 1)
	{
		for (int i = 1; i <= n; i++)
			if (h[i] != t[i])
				return 0;
		return 1;
	}
	for (int i = 1; i <= n; i++)
	{
		s[i][++t[i]] = a[u];
		if (dfs(u + 1))
		{
			back[++backtop][0] = 1, back[backtop][1] = i;
			return 1;
		}
		t[i]--;
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			if (i == j)
				continue;
			if (s[i][h[i]] == s[j][h[j]])
			{
				h[i]++, h[j]++;
				if (dfs(u))
				{
					back[++backtop][0] = 2, back[backtop][1] = i, back[backtop][2] = j;
					return 1;
				}
			}
		}
	return 0;
}
int main()
{
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	for (int ii = 1; ii <= T; ii++)
	{
		cin >> n >> m >> k;
		for (int i = 1; i <= m; i++)
			cin >> a[i];
		dfs(1);
		cout << backtop << endl;
		for (int i = backtop; i >= 1; i--)
		{
			cout << back[i][0] << " " << back[i][1] << " ";
			if (back[i][0] == 2)
				cout << back[i][2];
			cout << endl;
		}
	}
	return 0;
}