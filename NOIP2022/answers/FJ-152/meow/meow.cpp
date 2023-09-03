
#include <bits/stdc++.h>

using namespace std; const int maxm = 2e6 + 5, maxn = 3e2 + 5; typedef long long ll;

int n, m, k, a[maxm];

vector<int> tg[maxn];

vector<pair<int, int> > op;

struct node
{
	int a[3][4];
	
	vector<pair<int, int> > op; int FR;
	
	ll hash()
	{
		ll res = 0;
		for (int i = 0; i < 3; i++) for (int j = 0; j < 4; j++) res = res * 5 + a[i][j];
		return res;
	}
} ori;

map<ll, node> mp[maxm];

inline void solve()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) scanf("%d", a + i);
	if (k == 2 * n - 2)
	{
		for (int i = 1; i <= m; i++)
		{
			int I = (a[i] + 1 >> 1);
			int ty = 1 + (a[i] & 1);
			if (!tg[I].size())
			{
				op.push_back({ 0, I });
				tg[i].push_back(ty);
			}
			else
			{
				if (ty == tg[I][0])
				{
					op.push_back({ 0, n });
					op.push_back({ I, n });
					tg[I].erase(tg[I].begin());
				}
				else
				{
					op.push_back({ 0, I });
					if (tg[I].size() == 1)
					{
						tg[I].push_back(ty);
					}
					else
					{
						tg[I].pop_back();
					}
				}
			}
		}
	}
	else
	if (n <= 3)
	{
		mp[0][ori.hash()] = ori;
		for (int i = 1; i <= m; i++)
		{
			for (auto it = mp[i - 1].begin(); it != mp[i - 1].end(); it++)
			{
				for (int x = 0; x < n; x++)
				{
					auto e = it->second;
					int y = 0;
					while (y < 4 && e.a[x][y]) y++;
					if (y == 4) continue;
					e.a[x][y] = a[i];
					e.FR = it->first;
					e.op = { { 0, x + 1 } };
					if (y && e.a[x][y] == e.a[x][y - 1]) e.a[x][y] = e.a[x][y - 1] = 0;
					for (int z = 0; z < n; z++)
					{
						for (int h = z + 1; h < n; h++)
						{
							while (e.a[z][0] && e.a[h][0] && e.a[z][0] == e.a[h][0])
							{
								for (int j = 0; j < 3; j++) e.a[z][j] = e.a[z][j + 1]; e.a[z][3] = 0;
								for (int j = 0; j < 3; j++) e.a[h][j] = e.a[h][j + 1]; e.a[h][3] = 0;
								e.op.push_back({ z + 1, h + 1 });
							}
						}
					}
					reverse(e.op.begin(), e.op.end());
					mp[i][e.hash()] = e;
				}
			}
		}
		ll u = mp[m].begin()->first;
		for (int i = m; i; i--)
		{
			for (auto e : mp[i][u].op) op.push_back(e);
			u = mp[i][u].FR;
		}
		reverse(op.begin(), op.end());
		for (int i = 0; i <= m; i++) mp[i].clear();
	}
	for (int i = 1; i <= n; i++) tg[i].clear();
	printf("%d\n", int(op.size()));
	for (auto e : op) if (e.first == 0) printf("1 %d\n", e.second); else printf("2 %d %d\n", e.first, e.second);
	op.clear();
}

int main()
{
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) solve();
}
