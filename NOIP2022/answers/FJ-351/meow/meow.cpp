#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;
const LL N = 310, M = 1e6 + 10, INF = 1e18;

LL n, m, k;
LL a[M], now;
LL op[M * 2];
PLL cz[M * 2];
queue<LL> q[N];
bool ok;

bool check()
{
	for (LL i = 1; i <= n; i ++ )
		if (q[i].size())
			return false;
	return true;
}

void dfs(LL x)
{
	if (ok) return;
	if (x > m * 2) return;
	if (x && now > m && check())
	{
		printf("%lld\n", x);
		for (LL i = 1; i <= x; i ++ )
		{
			printf("%lld ", op[x]);
			if (op[x] == 1) printf("%lld\n", cz[x].first);
			else printf("%lld %lld\n", cz[x].first, cz[x].second);
		}
		ok = true;
		return;
	}
	for (LL i = 1; i <= n; i ++ ) 
	{
		LL t = INF;
		if (q[i].size()) t = q[i].back();
		bool flag = false;
		q[i].push(a[now]);
		if (t == a[now])
		{
			q[i].pop(); q[i].pop();
			flag = true;
		}
		now ++ ;
		op[x] = 1; cz[x] = {i, INF};
		dfs(x + 1);
		if (!flag) q[i].pop();
		else q[i].push(t);
		now -- ;
		op[x] = 0; cz[x] = {0, 0};
	}
	for (LL i = 1; i <= n; i ++ )
		for (LL j = 1; j <= n; j ++ )
		{
			if (i == j) continue;
			if (q[i].empty() || q[j].empty()) continue;
			if (q[i].back() != q[j].back()) continue;
			LL ti = q[i].back(), tj = q[j].back();
			q[i].pop(); q[j].pop();
			op[x] = 2; cz[x] = {i, j};
			dfs(x + 1);
			q[i].push(ti); q[j].push(tj);
			op[x] = 0; cz[x] = {0, 0};
		}
}

int main()
{
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	LL T;
	scanf("%lld", &T);
	while (T -- )
	{
		scanf("%lld%lld%lld", &n, &m, &k);
		for (LL i = 1; i <= m; i ++ ) scanf("%lld", &a[i]);
		ok = false;
		now = 1;
		for (LL i = 1; i <= n; i ++ )
			while (q[i].size())
				q[i].pop();
		dfs(0);
	}
	return 0;
}
