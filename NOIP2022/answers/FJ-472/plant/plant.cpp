//NOIP2022 RP++
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
ll T, id, n, m, c, f;
bool a[1005][1005];
ll awa[1005][1005][2], qwq[1005][1005][2];
inline bool check(ll x, ll y)
{
	return 1 <= x && x <= n && 1 <= y && y <= m && a[x][y] == 0;
}
/*
0:x
1:y
 yyym
x
x
x
n
*/
int main()
{
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T >> id;
	for (ll ii = 1; ii <= T; ii++)
	{
		cin >> n >> m >> c >> f;
		char ch;
		for (ll i = 1; i <= n; i++)
			for (ll j = 1; j <= m; j++)
				cin >> ch, a[i][j] = ch - '0';
		if (c == 0 && f == 0)
		{
			cout << "0 0" << endl;
			continue;
		}
		for (ll i = n; i >= 1; i--)
			for (ll j = m; j >= 1; j--)
				if (a[i][j] == 1)
					awa[i][j][0] = awa[i][j][1] = 0;
				else
					awa[i][j][0] = awa[i + 1][j][0] + 1, awa[i][j][1] = awa[i][j + 1][1] + 1;
//		for (ll i = 1; i <= n; cout << endl, i++)
//			for (ll j = 1; j <= m; j++)
//				cout << "(" << awa[i][j][0] << "," << awa[i][j][1] << ") ";
//		cout << endl;
		ll ansc = 0, ansf = 0;
		for (ll i = n; i >= 1; i--)
			for (ll j = m; j >= 1; j--)
			{
				if (a[i][j] == 1)
					continue;
				if (check(i - 1, j) && check(i - 2, j))
				{
					qwq[i][j][0] = awa[i][j][1] - 1 + qwq[i + 1][j][0], qwq[i][j][0] %= mod;
					qwq[i][j][1] = (awa[i][j][1] - 1) * (awa[i][j][0] - 1), qwq[i][j][1] %= mod;
				}
			}
//		for (ll i = 1; i <= n; cout << endl, i++)
//			for (ll j = 1; j <= m; j++)
//				cout << "(" << qwq[i][j][0] << "," << qwq[i][j][1] << ") ";
		for (ll x = 1; x <= n; x++)
			for (ll y = 1; y <= m; y++)
			{
				if (awa[x][y][1] <= 1 || awa[x][y][0] <= 2)
					continue;
				ansc += (awa[x][y][1] - 1) * qwq[x + 2][y][0];
				ansf += (awa[x][y][1] - 1) * qwq[x + 2][y][1];
			}
		cout << c * ansc << " " << f * ansf << endl;
	}
	return 0;
}